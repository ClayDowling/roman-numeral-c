/**
 * Roman numeral conversion routines
 */

#ifndef _ROMAN_CONVERT_H_
#define _ROMAN_CONVERT_H_

#define INVALID_NUMERAL 0

extern const char *OVERFLOW;
extern const char *ZERO;

unsigned rn_toint(const char*);
char* rn_toroman(int);

#endif
