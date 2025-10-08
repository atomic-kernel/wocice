#pragma once

#if !defined(__CHAR_BIT__) || !defined(__SIZEOF_LONG__) || !defined(__SIZEOF_LONG_LONG__)
#error "!defined(__CHAR_BIT__) || !defined(__SIZEOF_LONG__) || !defined(__SIZEOF_LONG_LONG__)"
#endif

#define __BITS_PER_LONG (__CHAR_BIT__ * __SIZEOF_LONG__)

#define __BITS_PER_LONG_LONG (__CHAR_BIT__ * __SIZEOF_LONG_LONG__)
