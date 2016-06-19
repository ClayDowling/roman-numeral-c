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

START_TEST(rn_add_onOverflow_returnsOVERFLOW)
{
	ck_assert_str_eq(rn_add("D", "D"), "OVERFLOW");
}
END_TEST

START_TEST(rn_add_givenDCCCandXCIX_returnsRNMAX)
{
	ck_assert_str_eq(rn_add("DCCC", "XCIX"), "DCCCXCIX");
}
END_TEST


TCase* tcase_operators(void)
{
	TCase *tc;

	tc = tcase_create("Operators");
	tcase_add_test(tc, rn_add_givenIVandV_returnsIX);
	tcase_add_test(tc, rn_add_givenNULLlhs_returnsNull);
	tcase_add_test(tc, rn_add_givenNULLrhs_returnsNull);
	tcase_add_test(tc, rn_add_onOverflow_returnsOVERFLOW);
	tcase_add_test(tc, rn_add_givenDCCCandXCIX_returnsRNMAX);

	return tc;
}
