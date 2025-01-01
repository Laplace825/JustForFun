#pragma once

/*! Simple matrix multiplication with unrolling

   The code is a simple example of how to use template
   meta-programming to unroll loops About C=alpha*AxB+beta*C

   All the matrix is arranged in row-major order.

   A(M,K) B(K,N) C(M,N) (dimension)
 */
#include <config.h>
#include <omp.h>

#include <type_traits>

namespace lap {

// Specializations for terminating the recursion
template < int I, int J, int K, int M, int N, int L, typename T >
    requires std::is_arithmetic_v< T >
struct DaABpbCUnrollCore {
    _LAP static void compute(
      const T& alpha, const T& beta, const T* A, const T* B, T* C) {
        T sum = 0;
#pragma omp parallel for reduction(+ : sum)
        for (int l = 0; l < K; ++l) {
            sum += alpha * A[I * L + l] * B[l * N + J];
        }
        C[I * N + J] = beta * C[I * N + J] + sum;
        if constexpr (J + 1 < N) {
            DaABpbCUnrollCore< I, J + 1, K, M, N, L, T >::compute(
              alpha, beta, A, B, C);
        }
        else if constexpr (I + 1 < M) {
            DaABpbCUnrollCore< I + 1, 0, K, M, N, L, T >::compute(
              alpha, beta, A, B, C);
        }
    }
};

// A(M,K) B(K,N) C(M,N) (dimension)
template < int M, int K, int N, typename T >
_LAP void DaABpbC_unroll(
  const T& alpha, const T* A, const T* B, const T& beta, T* C) {
    DaABpbCUnrollCore< 0, 0, K, M, N, K, T >::compute(alpha, beta, A, B, C);
}

} // namespace lap
