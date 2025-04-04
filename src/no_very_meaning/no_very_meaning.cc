#include <iostream>

namespace lap {

class MyClass {};

constexpr auto fun(MyClass _) -> int { return 1; }

} // namespace lap

int main() {
    // auto mut_lambda = [i = 0]() mutable { return i++; };
    // std::cout << mut_lambda() << std::endl;
    // std::cout << mut_lambda() << std::endl;
    // std::cout << mut_lambda() << std::endl;
    // ADL
    constexpr auto x = fun(lap::MyClass{});
    return 0;
}
