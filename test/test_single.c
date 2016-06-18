#include <stdlib.h>
#include <stdio.h>

#include <check.h>

#include "../src/roman.h"

static char *test_value[] = {"J", "I", "V", "X", "L", "C", "D"};
static int expected_value[] = {INVALID_NUMERAL, 1, 5, 10, 50, 100, 500};

START_TEST(rn_toint_singledigit_test)
{
	ck_assert_int_eq(rn_toint(test_value[_i]), expected_value[_i]);
}
END_TEST

TCase *tcase_single_digits(void)
{
	TCase *tc;
	int num_cases = sizeof(expected_value) / sizeof(int);

	tc= tcase_create("Single Digits");
	tcase_add_loop_test(tc, rn_toint_singledigit_test, 0, num_cases);

	return tc;
}

