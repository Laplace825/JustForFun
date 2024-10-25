#pragma once

#include <type_traits>

#include "marco.h"

namespace lap {
template < typename ObjT >
consteval auto get_typename(ObjT&& _) {
    return _get_typename_impl< std::decay_t< ObjT >, std::integral_constant<bool, true> >::value;
}

} // namespace lap
