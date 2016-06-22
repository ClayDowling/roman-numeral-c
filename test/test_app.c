/**
 * Test the application implementation.
 */

#include "../src/roman_app.h"
#include <check.h>

START_TEST(calculate_withIVplusVI_givesX)
{
	ck_assert_str_eq(calculate("IV", '+', "VI"), "X");
}
END_TEST

START_TEST(calculate_withVIminusIV_givesII)
{
	ck_assert_str_eq(calculate("VI", '-', "IV"), "II");
}
END_TEST

START_TEST(caluclate_calledTwice_returnsSamePointer)
{
	const char *first_answer;
	const char *second_answer;

	first_answer = calculate("VI", '-', "IV");
	second_answer = calculate("VI", '+', "IV");

	ck_assert_ptr_eq(first_answer, second_answer);
}
END_TEST

START_TEST(calculate_withBogusNumerals_returnsNil)
{
	ck_assert_str_eq(calculate("BAD", '+', "WORSE"), "Nil");
}
END_TEST

TCase *tcase_app(void)
{
	TCase *tc;

	tc = tcase_create("app");

	tcase_add_test(tc, calculate_withIVplusVI_givesX);
	tcase_add_test(tc, calculate_withVIminusIV_givesII);
	tcase_add_test(tc, caluclate_calledTwice_returnsSamePointer);
	tcase_add_test(tc, calculate_withBogusNumerals_returnsNil);

	return tc;
}
