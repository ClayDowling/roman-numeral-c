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

START_TEST(rn_toint_givenVI_returns6)
{
	ck_assert_int_eq(rn_toint("VI"), 6);
}
END_TEST

START_TEST(rn_toint_givenIV_returns4)
{
	ck_assert_int_eq(rn_toint("IV"), 4);
}
END_TEST

START_TEST(rn_toint_givenIX_returns9)
{
	ck_assert_int_eq(rn_toint("IX"), 9);
}
END_TEST

TCase* tcase_complex_numerals(void)
{
	TCase *tc;

	tc = tcase_create("Complex Numerals");
	tcase_add_test(tc, rn_toint_givenII_returns2);
	tcase_add_test(tc, rn_toint_givenVI_returns6);
	tcase_add_test(tc, rn_toint_givenIV_returns4);
	tcase_add_test(tc, rn_toint_givenIX_returns9);

	return tc;
}
