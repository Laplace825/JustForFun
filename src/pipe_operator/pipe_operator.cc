#include <algorithm>
#include <numeric>
#include <vector>

#if __cplusplus >= 202002L
#include <print>
#include <ranges>

template < typename U, typename Fn >
    requires std::regular_invocable< Fn, U& > && std::is_arithmetic_v< U >
constexpr auto operator|(U u, const Fn& fn) {
    return fn(u);
}

int main() {
    using namespace std::literals;

    constexpr auto power = []< typename ArgT >(ArgT& x) {
        x *= x;
        return x;
    };

    [[maybe_unused]] constexpr auto after_power = 2 | power;

    std::vector< int > v(10);
    std::iota(v.begin(), v.end(), 1);

    std::for_each(v.begin(), v.end(), [](int x) { std::print("{} ", x); });
    std::println("");

    /// @brief:
    /// we filter out even numbers, then we square them and take the first 3
    /// elements, then we reverse the sequence and finally we prepend a string
    /// to each element
    ///
    /// @note:
    /// the take function will cause to transform just the first 3 elements
    auto result = v | std::views::filter([](int x) { return !(x & 1); }) |
                  std::views::transform(power) | std::views::take(3) |
                  std::views::transform([](int x) {
                      return "The number is "s + std::to_string(x);
                  });

    for (auto&& x : result) {
        std::println("{}", x);
    }

    std::for_each(v.begin(), v.end(), [](int x) { std::print("{} ", x); });
    std::println("");
}

#else
int main() { return 1; }
#endif
