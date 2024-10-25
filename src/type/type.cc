#include <print>

#include "type/get_typename.h"

class Bob {};

SET_TYPENAME(Bob, class Bob);

SET_TYPENAME_THE_SAME_AS(int16_t*);
SET_TYPENAME_THE_SAME_AS(int);
SET_TYPENAME_THE_SAME_AS(int*);

int main() {
    int integer = 1;

    Bob bob;

    int32_t* ptr32 = &integer;
    int16_t* ptr16 = reinterpret_cast< int16_t* >(ptr32);

    std::println("{}", lap::get_typename(integer));
    std::println("{}", lap::get_typename(bob));
    std::println("{}", lap::get_typename(ptr32));
    std::println("{}", lap::get_typename(ptr16));

    return 0;
}
