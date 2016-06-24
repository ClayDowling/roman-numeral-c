/**
 * Roman numeral conversion routines
 */

#ifndef _ROMAN_CONVERT_H_
#define _ROMAN_CONVERT_H_

#include <stdlib.h>

#define INVALID_NUMERAL 0

extern const char *OVERFLOW;
extern const char *ZERO;

unsigned rn_toint(const char*);
void rn_toroman(int num, char* buffer, size_t buffer_length);

#endif
