#include <print>

template < std::size_t N >
constexpr auto get_or() -> int {
    try {
        // throw std::runtime_error("error");
        return N;
    } catch (...) {
        return 1;
    }
}

int main() {
    constexpr auto num = get_or< 10 >();

    return 0;
}
