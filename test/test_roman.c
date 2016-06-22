#include <stdlib.h>
#include <stdio.h>

#include <check.h>

#include "tcase_roman.h"

Suite *app_suite(void)
{
	Suite *s;

	s = suite_create("application");
	
	suite_add_tcase(s, tcase_app());

	return s;
}

Suite *roman_suite(void)
{
	Suite *s;

	s = suite_create("roman-numerals");

	suite_add_tcase(s, tcase_single_digits());
	suite_add_tcase(s, tcase_complex_numerals());
	suite_add_tcase(s, tcase_toarabic());
	suite_add_tcase(s, tcase_operators());

	return s;
}

int main(int argc, char **argv)
{
	Suite *s;
	SRunner *runner;
	int number_fails;

	s = roman_suite();
	runner = srunner_create(s);
	srunner_add_suite(runner, app_suite());

	srunner_run_all(runner, CK_NORMAL);
	number_fails = srunner_ntests_failed(runner);
	srunner_free(runner);

	return number_fails;
}

