#if __cplusplus >= 202302L
#include <expected>
#include <print>

#include "rustlike/result.h"

using lap::Result;
using lap::Err;
using lap::Ok;

enum class ErrorAlgorithm : int {
    DivisionByZero,
};

template < typename T >
    requires std::is_arithmetic_v< T >
constexpr auto divide(T a, T b) -> Result< T, ErrorAlgorithm > {
    if (b == 0) {
        return Err(ErrorAlgorithm::DivisionByZero);
    }
    return Ok(a / b);
}

int main() {
    if (constexpr auto res = divide(10, 0); res.has_value()) {
        std::println("Result: {}", res.value());
    }
    else {
        std::println("Error: {}", static_cast< int >(res.error()));
    }
}

#else
int main() { return 0; }
#endif
