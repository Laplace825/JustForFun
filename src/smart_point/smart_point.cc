#include "my_print/my_print.h"

int main() {
    std::unique_ptr< int > b = std::make_unique< int >(10);
    return 0;
}
