#include "matrix_unroll/matrix_unroll.h"

#include <algorithm>
#include <array>
#include <cstdlib>

#include "my_print/my_print.h"
#include "timer/timer.h"

int main() {
    using lap::DaABpbC_unroll;

    // 32x64
    std::array< double, 32 * 64 > A{0};

    std::ranges::for_each(
      A, [](double& a) { a = std::rand() % 4 + (std::rand() % 10) * 0.1; });

    // 64x20
    std::array< double, 64 * 20 > B{0};
    std::ranges::for_each(
      B, [](double& b) { b = std::rand() % 32 + (std::rand() % 10) * 0.1; });

    // 32x20
    std::array< double, 32 * 20 > C{0};
    std::ranges::for_each(
      C, [](double& c) { c = std::rand() % 10 + (std::rand() % 10) * 0.1; });

    {
        lap::TimerRAII t{};
        DaABpbC_unroll< 32, 64, 20 >(1.2, A.data(), B.data(), 1.0, C.data());
    }

    std::ranges::for_each(
      C, [](const double& c) { lap::println("{:.2f}", c); });

    return 0;
}
