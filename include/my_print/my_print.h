#include <iostream>

namespace lap {
#if __cplusplus >= 201703L
template < typename... ArgsT >
void print(ArgsT&&... args) {
    (std::cout << ... << args);
}
#else
template < typename... ArgsT >
void print(ArgsT&&... args) {
    (void)std::initializer_list< int >{(std::cout << args, 0)...};
}
#endif

template < typename... ArgsT >
void println(ArgsT&&... args) {
    print(std::forward< ArgsT >(args)...);
    std::cout << std::endl;
}

} // namespace lap
