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

Suite *roman_suite(void)
{
	Suite *s;
	TCase *tc_convert_single;

	s = suite_create("Roman");

	tc_convert_single = tcase_create("Single Digits");
	tcase_add_test(tc_convert_single, rn_toint_givenJ_returnsINVALIDNUMERAL);
	tcase_add_test(tc_convert_single, rn_toint_givenI_returns1);
	tcase_add_test(tc_convert_single, rn_toint_givenV_returns5);
	tcase_add_test(tc_convert_single, rn_toint_givenX_returns10);
	tcase_add_test(tc_convert_single, rn_toint_givenL_returns50);
	tcase_add_test(tc_convert_single, rn_toint_givenC_returns100);

	suite_add_tcase(s, tc_convert_single);

	return s;
}

int main(int argc, char **argv)
{
	Suite *s;
	SRunner *runner;
	int number_fails;

	s = roman_suite();
	runner = srunner_create(s);

	srunner_run_all(runner, CK_NORMAL);
	number_fails = srunner_ntests_failed(runner);
	srunner_free(runner);

	return number_fails;
}

