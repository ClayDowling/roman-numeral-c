/**
 * Roman Numerals digit conversion interface
 *
 */

#ifndef _ROMAN_H_
#define _ROMAN_H_

#define INVALID_NUMERAL 0
#define RN_MAX 899

unsigned rn_toint(const char*);
char* rn_toroman(int);
char* rn_add(const char*, const char*);

#endif
