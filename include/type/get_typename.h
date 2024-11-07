#pragma once

#include <tuple>
#include <type_traits>

namespace lap {

template < typename... ArgsT >
struct type_list {
    template < template < typename... > class Fn >
    using apply = Fn< ArgsT... >;
};

} // namespace lap

namespace lap {

template < typename... >
struct _get_type_from_tempclass_impl;

template < template < typename... > class TemplateClass, typename... ArgsT >
struct _get_type_from_tempclass_impl< TemplateClass< ArgsT... > > {
    using tuple_type = std::tuple< ArgsT... >;
};

template < std::size_t N, typename TemplateClass >
struct type_from_tempclass_at {
  private:
    using _type =
      typename _get_type_from_tempclass_impl< TemplateClass >::tuple_type;

  public:
#if __cplusplus >= 201703L
    using type = typename std::tuple_element_t< N, _type >;
#else
    using type = typename std::tuple_element< N, _type >::type;
#endif
};

#if __cplusplus >= 201703L

template < std::size_t N, typename TemplateClass >
using type_from_tempclass_at_t =
  typename type_from_tempclass_at< N, TemplateClass >::type;

#endif

} // namespace lap

/// @note: preinclude
#include "ctype_define.h"

namespace lap {

template < typename ObjT >
#if __cplusplus >= 201703L
consteval auto get_typename(ObjT&&) {
    return _get_typename_impl< std::decay_t< ObjT >,
      std::integral_constant< bool, true > >::value;
#else
constexpr auto get_typename(ObjT&&) {
    return _get_typename_impl< typename std::decay< ObjT >::type,
      std::integral_constant< bool, true > >::value;
#endif
}

} // namespace lap
