#include <iostream>

int main() {
    auto mut_lambda = [i = 0]() mutable { return i++; };
    std::cout << mut_lambda() << std::endl;
    std::cout << mut_lambda() << std::endl;
    std::cout << mut_lambda() << std::endl;
    return 0;
}
