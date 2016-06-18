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

TCase* tcase_operators(void)
{
	TCase *tc;

	tc = tcase_create("Operators");
	tcase_add_test(tc, rn_add_givenIVandV_returnsIX);

	return tc;
}
