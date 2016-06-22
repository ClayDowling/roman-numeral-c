/**
 * Defines all of the available test cases for the Roman Numerals suite
 */

#ifndef _TCASE_ROMAN_H_
#define _TCASE_ROMAN_H_

#include <check.h>

TCase* tcase_single_digits(void);
TCase* tcase_complex_numerals(void);
TCase* tcase_toarabic(void);
TCase* tcase_operators(void);

TCase* tcase_app(void);

#endif
