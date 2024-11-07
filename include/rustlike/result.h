#pragma once

#include <expected>
#include <string_view>

namespace lap {

template < typename VarT, typename Error >
using Result = std::expected< VarT, Error >;

template < typename ErrorT >
struct Err : private std::unexpected< ErrorT > {
    constexpr Err(ErrorT&& error)
        : std::unexpected< ErrorT >(std::forward< ErrorT >(error)), err(error) {
    }

    template < typename VarT >
    constexpr operator Result< VarT, ErrorT >() const {
        return std::unexpected< ErrorT >(err);
    }

  private:
    ErrorT err;
};

Err(const char*) -> Err< const std::string_view >;

constexpr decltype(auto) Ok(auto&& ok) { return ok; }
} // namespace lap
