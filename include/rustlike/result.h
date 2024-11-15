#pragma once

#include <expected>
#include <string_view>

namespace lap {

namespace rust {

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

template < typename VarT >
struct Ok {
    constexpr Ok(VarT&& v) : ok(std::forward< VarT >(v)) {}

    constexpr operator VarT() const { return ok; }

  private:
    const VarT& ok;
};

// constexpr decltype(auto) Ok(auto&& ok) { return ok; }

} // namespace rust
} // namespace lap
