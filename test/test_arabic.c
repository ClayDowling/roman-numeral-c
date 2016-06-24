/**
 * Test conversion of integer to roman numerals
 */

#include <stdlib.h>
#include <check.h>

#include "tcase_roman.h"
#include "../src/roman_convert.h"

#define BUFFER_LENGTH 20

static int test_value[] = {
	1,  2,   3,  4,
	5,  9,  10, 11,
	19, 20, 21, 24,
	25, 49, 50, 51,
	99, 100, 101, 499,
	500, 501, 0, -1,
	1000, 1996
	};
static const char *expected_value[] = {
	"I", "II", "III", "IV",
	"V", "IX", "X", "XI",
	"XIX", "XX", "XXI", "XXIV",
	"XXV", "XLIX", "L", "LI",
	"XCIX", "C", "CI", "CDXCIX",
	"D", "DI", "Nil", "Et cecidit in finem",
	"M", "MCMXCVI"
	};


START_TEST(rn_toroman_fromint)
{
	static char actual[BUFFER_LENGTH];

	rn_toroman(test_value[_i], actual, BUFFER_LENGTH);
	ck_assert_ptr_ne(actual, NULL);
	ck_assert_msg(strcmp(actual, expected_value[_i]) == 0,
			"Expected %s for %d, actual was %s",
			expected_value[_i], test_value[_i], actual);
}
END_TEST

TCase* tcase_toarabic(void)
{
	TCase *tc;
	int numtests = sizeof(test_value) / sizeof(int);

	tc = tcase_create("arabic_to_roman");
	tcase_add_loop_test(tc, rn_toroman_fromint, 0, numtests);

	return tc;
}
