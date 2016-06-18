#include <stdlib.h>
#include <stdio.h>

#include <check.h>

#include "../src/roman.h"

START_TEST(rn_toint_givenI_returns1)
{
	ck_assert_int_eq(rn_toint("I"), 1);
}
END_TEST

Suite *roman_suite(void)
{
	Suite *s;
	TCase *tc_convert_single;

	s = suite_create("Roman");

	tc_convert_single = tcase_create("Single Digits");
	tcase_add_test(tc_convert_single, rn_toint_givenI_returns1);

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

