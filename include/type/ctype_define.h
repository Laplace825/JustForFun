#pragma once

/// @brief: define the type name for the type
///
/// used to make get_typename work

// #include <config.h>

#include <cstdint>

#include "macro.h"

SET_TYPENAME(double, f64);
SET_TYPENAME(float, f32);
SET_TYPENAME(int8_t, i8);
SET_TYPENAME(char, i8);
SET_TYPENAME(int16_t, i16);
SET_TYPENAME(int32_t, i32);
SET_TYPENAME(int64_t, i64);

SET_TYPENAME(uint8_t, u8);
SET_TYPENAME(uint16_t, u16);
SET_TYPENAME(uint32_t, u32);
SET_TYPENAME(uint64_t, u64);

SET_TYPENAME(void*, void_ptr);
SET_TYPENAME(double*, f64_ptr);
SET_TYPENAME(float*, f32_ptr);
SET_TYPENAME(int8_t*, i8_ptr);
SET_TYPENAME(char*, i8_ptr);
SET_TYPENAME(int16_t*, i16_ptr);
SET_TYPENAME(int32_t*, i32_ptr);
SET_TYPENAME(int64_t*, i64_ptr);

SET_TYPENAME(uint8_t*, i8_ptr);
SET_TYPENAME(uint16_t*, i16_ptr);
SET_TYPENAME(uint32_t*, i32_ptr);
SET_TYPENAME(uint64_t*, i64_ptr);
