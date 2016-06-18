/**
 * Test cases for complex numerals, i.e. with more than one character
 */

#include <check.h>
#include "tcase_roman.h"
#include "../src/roman.h"

START_TEST(rn_toint_givenII_returns2)
{
	ck_assert_int_eq(rn_toint("II"), 2);
}
END_TEST

TCase* tcase_complex_numerals(void)
{
	TCase *tc;

	tc = tcase_create("Complex Numerals");
	tcase_add_test(tc, rn_toint_givenII_returns2);

	return tc;
}
