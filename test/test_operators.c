/**
 * Tests for operators
 */

#include <check.h>

#include "../src/roman.h"

START_TEST(rn_add_givenIVandV_returnsIX)
{
	ck_assert_str_eq(rn_add("IV", "V"), "IX");
}
END_TEST

START_TEST(rn_add_givenNULLlhs_returnsNull)
{
	ck_assert_ptr_eq(rn_add(NULL, "V"), NULL);
}
END_TEST

START_TEST(rn_add_givenNULLrhs_returnsNull)
{
	ck_assert_ptr_eq(rn_add("V", NULL), NULL);
}
END_TEST

START_TEST(rn_add_onOverflow_returnsDegenero)
{
	ck_assert_str_eq(rn_add("MMM", "M"), "Degenero");
}
END_TEST

START_TEST(rn_subtract_givenMCMLXXVIandMCMLXX_returnsVI)
{
	ck_assert_str_eq(rn_subtract("MCMLXXVI", "MCMLXX"), "VI");
}
END_TEST

START_TEST(rn_subtract_givenXandIV_returnsVI)
{
	ck_assert_str_eq(rn_subtract("X", "IV"), "VI");
}
END_TEST

START_TEST(rn_subtract_givenCandXCIX_returnsI)
{
	ck_assert_str_eq(rn_subtract("C", "XCIX"), "I");
}
END_TEST

START_TEST(rn_subtract_givenNULLandIV_returnsNULL)
{
	ck_assert_ptr_eq(rn_subtract(NULL, "IV"), NULL);
}
END_TEST

START_TEST(rn_subtract_givenIVandNULL_returnsNULL)
{
	ck_assert_ptr_eq(rn_subtract("IV", NULL), NULL);
}
END_TEST

START_TEST(rn_subtract_giveXandXX_returnsDegenero)
{
	ck_assert_str_eq(rn_subtract("X", "XX"), "Degenero");
}
END_TEST

START_TEST(rn_subtract_givenXandX_returnsNil)
{
	ck_assert_str_eq(rn_subtract("X", "X"), "Nil");
}
END_TEST

TCase* tcase_operators(void)
{
	TCase *tc;

	tc = tcase_create("Operators");
	tcase_add_test(tc, rn_add_givenIVandV_returnsIX);
	tcase_add_test(tc, rn_add_givenNULLlhs_returnsNull);
	tcase_add_test(tc, rn_add_givenNULLrhs_returnsNull);
	tcase_add_test(tc, rn_add_onOverflow_returnsDegenero);
	tcase_add_test(tc, rn_subtract_givenXandIV_returnsVI);
	tcase_add_test(tc, rn_subtract_givenCandXCIX_returnsI);
	tcase_add_test(tc, rn_subtract_givenNULLandIV_returnsNULL);
	tcase_add_test(tc, rn_subtract_givenIVandNULL_returnsNULL);
	tcase_add_test(tc, rn_subtract_giveXandXX_returnsDegenero);
	tcase_add_test(tc, rn_subtract_givenXandX_returnsNil);
	tcase_add_test(tc, rn_subtract_givenMCMLXXVIandMCMLXX_returnsVI);

	return tc;
}
