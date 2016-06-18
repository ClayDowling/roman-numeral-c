#include <stdlib.h>
#include <stdio.h>

#include <check.h>

#include "../src/roman.h"

START_TEST(rn_toint_givenJ_returnsINVALIDNUMERAL)
{
	ck_assert_int_eq(rn_toint("J"), INVALID_NUMERAL);
}
END_TEST

START_TEST(rn_toint_givenI_returns1)
{
	ck_assert_int_eq(rn_toint("I"), 1);
}
END_TEST

START_TEST(rn_toint_givenV_returns5)
{
	ck_assert_int_eq(rn_toint("V"), 5);
}
END_TEST

START_TEST(rn_toint_givenX_returns10)
{
	ck_assert_int_eq(rn_toint("X"), 10);
}
END_TEST

START_TEST(rn_toint_givenL_returns50)
{
	ck_assert_int_eq(rn_toint("L"), 50);
}
END_TEST

START_TEST(rn_toint_givenC_returns100)
{
	ck_assert_int_eq(rn_toint("C"), 100);
}
END_TEST

START_TEST(rn_toint_givenD_returns500)
{
	ck_assert_int_eq(rn_toint("D"), 500);
}
END_TEST

TCase *tcase_single_digits(void)
{
	TCase *tc_convert_single;

	tc_convert_single = tcase_create("Single Digits");
	tcase_add_test(tc_convert_single, rn_toint_givenJ_returnsINVALIDNUMERAL);
	tcase_add_test(tc_convert_single, rn_toint_givenI_returns1);
	tcase_add_test(tc_convert_single, rn_toint_givenV_returns5);
	tcase_add_test(tc_convert_single, rn_toint_givenX_returns10);
	tcase_add_test(tc_convert_single, rn_toint_givenL_returns50);
	tcase_add_test(tc_convert_single, rn_toint_givenC_returns100);
	tcase_add_test(tc_convert_single, rn_toint_givenD_returns500);

	return tc_convert_single;
}

