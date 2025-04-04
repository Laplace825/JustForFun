#pragma once

#include <config.h>

#include <type_traits>
#ifndef LAP_MACRO_H
#define LAP_MACRO_H

namespace lap {

template < typename... ObjT >
struct _get_typename_impl;

} // namespace lap

#define _SET_TYPENAME_IMPL(obj, obj_typename)                \
    template < typename ObjT >                               \
    struct lap::_get_typename_impl< ObjT,                    \
      typename std::is_same< ObjT, decltype(obj) >::type > { \
        static constexpr const auto value = #obj_typename;   \
    };

#define SET_TYPENAME(which, name) \
    _SET_TYPENAME_IMPL(std::decay< which >::type{}, name)

#define SET_TYPENAME_THE_SAME_AS(name) \
    _SET_TYPENAME_IMPL(std::decay< name >::type{}, name)

#endif
