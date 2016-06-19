/**
 * Test cases for complex numerals, i.e. with more than one character
 */

#include <check.h>
#include "tcase_roman.h"
#include "../src/roman.h"

static char *test_value[]   = {"II", "VI", "IV", "IX", "VII", "IIII",
	"XXXX"          , "CCCC",         "VV"           , "IIV",
	"XCIX"};
static int expected_value[] = {  2 ,   6 ,   4 ,   9 ,    7 , INVALID_NUMERAL,
	INVALID_NUMERAL, INVALID_NUMERAL, INVALID_NUMERAL, INVALID_NUMERAL,
	99};

START_TEST(rn_toint_translates_correctly)
{
	char *test;
	char *actual;
	int expected;

	test = test_value[_i];
	expected = expected_value[_i];
	actual = rn_toint(test);
	ck_assert_msg(actual == expected, 
			"rn_toint(%s) expected: %d actual: %d",
			test, expected, actual);
}
END_TEST

TCase* tcase_complex_numerals(void)
{
	TCase *tc;
	int num_cases = sizeof(expected_value) / sizeof(int);

	tc = tcase_create("Complex Numerals");
	tcase_add_loop_test(tc, rn_toint_translates_correctly, 0, num_cases);

	return tc;
}
