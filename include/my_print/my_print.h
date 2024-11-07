#include <iostream>
#if __cplusplus < 201703L

namespace lap {
template < typename... ArgsT >
void print(ArgsT&&... args) {
    (void)std::initializer_list< int >{(std::cout << args, 0)...};
}

#elif __cplusplus >= 201703L && __cplusplus < 202002L

template < typename... ArgsT >
void print(ArgsT&&... args) {
    (std::cout << ... << args);
}

template < typename... ArgsT >
void println(ArgsT&&... args) {
    print(std::forward< ArgsT >(args)...);
    std::cout << std::endl;
}

} // namespace lap
#endif

// C++ 20
#if __cplusplus >= 202002L
#include <format>

namespace lap {

template < typename... ArgsT >
void print(std::format_string< ArgsT... > fmt, ArgsT&&... args) {
    std::cout << std::format(fmt, std::forward< ArgsT >(args)...);
}

template < typename... ArgsT >
    requires(sizeof...(ArgsT) > 0)
void println(std::format_string< ArgsT... > fmt, ArgsT&&... args) {
    ::lap::print(fmt, std::forward< ArgsT >(args)...);
    std::cout << '\n';
}

} // namespace lap

#else
#include <print>
#endif
