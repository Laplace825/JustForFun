#pragma once

/// @brief: define the type name for the type
///
/// used to make get_typename work

// #include <config.h>

#include <cstdint>

#include "macro.h"

SET_TYPENAME(double, fp64);
SET_TYPENAME(float, fp32);
SET_TYPENAME(int8_t, int8);
SET_TYPENAME(char, int8);
SET_TYPENAME(int16_t, int16);
SET_TYPENAME(int32_t, int32);
SET_TYPENAME(int64_t, int64);

SET_TYPENAME(uint8_t, uint8);
SET_TYPENAME(uint16_t, uint16);
SET_TYPENAME(uint32_t, uint32);
SET_TYPENAME(uint64_t, uint64);

SET_TYPENAME(void*, void_ptr);
SET_TYPENAME(double*, fp64_ptr);
SET_TYPENAME(float*, fp32_ptr);
SET_TYPENAME(int8_t*, int8_ptr);
SET_TYPENAME(char*, int8_ptr);
SET_TYPENAME(int16_t*, int16_ptr);
SET_TYPENAME(int32_t*, int32_ptr);
SET_TYPENAME(int64_t*, int64_ptr);

SET_TYPENAME(uint8_t*, int8_ptr);
SET_TYPENAME(uint16_t*, int16_ptr);
SET_TYPENAME(uint32_t*, int32_ptr);
SET_TYPENAME(uint64_t*, int64_ptr);
