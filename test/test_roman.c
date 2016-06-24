#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <check.h>

#include "tcase_roman.h"

Suite *app_suite(void)
{
	Suite *s;

	s = suite_create("application");

	suite_add_tcase(s, tcase_app());

	return s;
}

Suite *operations_suite(void)
{
	Suite *s;

	s = suite_create("operations");

	suite_add_tcase(s, tcase_operators());

	return s;
}

Suite *roman_suite(void)
{
	Suite *s;

	s = suite_create("roman-numerals");

	suite_add_tcase(s, tcase_single_digits());
	suite_add_tcase(s, tcase_complex_numerals());
	suite_add_tcase(s, tcase_toarabic());

	return s;
}

int main(int argc, char **argv)
{
	Suite *s;
	SRunner *runner;
	int number_fails;
	int ch;
	enum print_output output = CK_NORMAL;

	while((ch = getopt(argc, argv, "smnve")) != -1) {
		switch(ch) {
			case 's':
				output = CK_SILENT;
				break;
			case 'm':
				output = CK_MINIMAL;
				break;
			case 'v':
				output = CK_VERBOSE;
				break;
			case 'e':
				output = CK_ENV;
				break;
			case 'n':
			default:
				output = CK_NORMAL;
		}
	}

	s = roman_suite();
	runner = srunner_create(s);
	srunner_add_suite(runner, operations_suite());
	srunner_add_suite(runner, app_suite());

	srunner_run_all(runner, output);
	number_fails = srunner_ntests_failed(runner);
	srunner_free(runner);

	return number_fails;
}
