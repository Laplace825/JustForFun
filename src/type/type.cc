#include <vector>

#include "my_print/my_print.h"
#include "type/get_typename.h"

class Bob {};

SET_TYPENAME(Bob, class Bob);

int main() {
    int integer = 1;

    Bob bob;

    int32_t* ptr32 = &integer;
    int16_t* ptr16 = reinterpret_cast< int16_t* >(ptr32);
    void* ptr_void = ptr16;

    lap::println(lap::get_typename(integer));
    lap::println(lap::get_typename(bob));
    lap::println(lap::get_typename(ptr32));
    lap::println(lap::get_typename(ptr16));
    lap::println(lap::get_typename(ptr_void));

    typename lap::type_from_tempclass_at< 0, std::vector< int > >::type
      another_integer = 1;

    using Tlist = lap::type_list< int, double, char >;

    typename lap::type_from_tempclass_at< 1, Tlist >::type fp64_number = 1.f;

    typename lap::type_from_tempclass_at< 1, std::vector< int > >::type
      int_allocater;
    return 0;
}
