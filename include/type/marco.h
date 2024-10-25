#pragma once

namespace lap {
template < typename... ObjT >
struct _get_typename_impl;
}

#define _SET_TYPENAME_IMPL(obj, obj_typename)        \
    template < typename ObjT >                       \
    struct lap::_get_typename_impl< ObjT,            \
      typename std::is_same< ObjT, decltype(obj) >::type > {      \
        static constexpr auto value = #obj_typename; \
    };

#define SET_TYPENAME(which, name) \
    _SET_TYPENAME_IMPL(std::decay_t< which >{}, name)

#define SET_TYPENAME_THE_SAME_AS(name) \
    _SET_TYPENAME_IMPL(std::decay_t< name >{}, name)
