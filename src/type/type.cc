#include <print>
#include <vector>

#include "type/get_typename.h"

class Bob {};

SET_TYPENAME(Bob, class Bob);

int main() {
    int integer = 1;

    Bob bob;

    int32_t* ptr32 = &integer;
    int16_t* ptr16 = reinterpret_cast< int16_t* >(ptr32);
    void* ptr_void = ptr16;

    std::println("{}", lap::get_typename(integer));
    std::println("{}", lap::get_typename(bob));
    std::println("{}", lap::get_typename(ptr32));
    std::println("{}", lap::get_typename(ptr16));
    std::println("{}", lap::get_typename(ptr_void));

    [[maybe_unused]] lap::type_from_tempclass_at_t< 0, std::vector< int > >
      another_integer = 1;

    using Tlist = lap::type_list< int, double, char >;

    [[maybe_unused]] lap::type_from_tempclass_at_t< 1, Tlist > fp64_number =
      1.f;

    [[maybe_unused]] lap::type_from_tempclass_at_t< 1, std::vector< int > >
      int_allocater;
    return 0;
}
