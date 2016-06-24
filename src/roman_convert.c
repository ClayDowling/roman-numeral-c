#include <stdlib.h>
#include <string.h>

#include "roman_convert.h"

const char *OVERFLOW = "Et cecidit in finem";
const char *ZERO = "Nil";

static unsigned roman_values[] = {1000, 500, 100, 50, 10, 5, 1};
unsigned roman_values_len = sizeof(roman_values) / sizeof(unsigned);

static unsigned should_subtract(unsigned left, unsigned right)
{
	switch(right) {
	case 1000:
		if (100 == left) return 900;
		break;
	case 500:
		if (100 == left) return 400;
		break;
	case 100:
		if (10 == left) return 90;
		break;
	case 50:
		if (10 == left) return 40;
		break;
	case 10:
		if (1 == left) return 9;
		break;
	case 5:
		if (1 == left) return 4;
		break;
	}
	return 0;
}

static int rn_can_display_with_subtraction(int target)
{
	int subtractible[] = {900, 400, 90, 40, 9, 4};
	int blocker[]      = {1000, 500, 100,50, 10, 5};
	int len = sizeof(subtractible) / sizeof(int);
	int i;

	for(i=0; i < len; ++i) {
		if (target >= subtractible[i] && target < blocker[i]) {
			return subtractible[i];
		}
	}

	return 0;
}

static char* rn_subtractible_roman_numeral(int value)
{
	switch(value) {
		case 900:
			return "CM";
		case 400:
			return "CD";
		case 90:
			return "XC";
		case 40:
			return "XL";
		case 9:
			return "IX";
		case 4:
			return "IV";
		default:
			return "";
	}
}

static int can_repeat(unsigned digit)
{
	switch(digit) {
	case 1:
	case 10:
	case 100:
	case 1000:
		return 1;
	default:
		return 0;
	}
}

static int rn_isvalid(int *candidate, int len)
{
	int repeats = 0;
	int norepeats = 0;
	int i;
	int last = 0;

	for(i = 0; i < len; ++i) {
		if (can_repeat(candidate[i])) {
			if (last == 0 || candidate[i] == last)
				repeats++;
			last = candidate[i];
			norepeats = 0;
			if (repeats > 3) {
			       	return 0;
			}
		} else {
			if (repeats > 1 && candidate[i-1] < candidate[i]) {
				return 0;
			}
			repeats = 0;
			norepeats++;
			if (norepeats > 1) {
				return 0;
			}
		}
	}
	return 1;
}

static unsigned rn_digit(char rn)
{
	switch(rn) {
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return INVALID_NUMERAL;
	}
}

static char rn_romandigit(int v)
{
	switch(v) {
		case 1:
			return 'I';
		case 5:
			return 'V';
		case 10:
			return 'X';
		case 50:
			return 'L';
		case 100:
			return 'C';
		case 500:
			return 'D';
		case 1000:
			return 'M';
		default:
			return '\0';
	}
}

static unsigned rn_sumdigits(int *digits, int size)
{
	unsigned i;
	int total = 0;
	unsigned subtract;

	for(i=0; i < size; ++i) {
		if (0 == digits[i]) {
			return INVALID_NUMERAL;
		}

		subtract = should_subtract(digits[i], digits[i+1]);
		if (subtract) {
			total += subtract;
			++i;
		}
		else {
			total += digits[i];
		}
	}

	if (total < 1) return INVALID_NUMERAL;
	return (unsigned)total;
}

unsigned rn_toint(const char* numeral)
{
	unsigned pos;
	int *values;
	int len;

	if (NULL == numeral) return INVALID_NUMERAL;

	len = strlen(numeral);
	values = (int*)calloc(len + 1, sizeof(int));

	for(pos = 0; numeral[pos]; ++pos) {
		values[pos] = rn_digit(numeral[pos]);
	}

	if (rn_isvalid(values, len) == 0) return INVALID_NUMERAL;
	return rn_sumdigits(values, len);

}

char* rn_toroman(int num)
{
	static char roman[20];
	int roman_pos = 0;
	int parts_pos;
	int part_candidate;
	int subtractible;

	if (num < 0) {
		return strdup(OVERFLOW);
	}
	if (0 == num) {
		return strdup(ZERO);
	}

	memset((void*)roman, 0, sizeof(roman));

	for(parts_pos = 0;
			num > 0 &&
			parts_pos < roman_values_len &&
			roman_pos < (sizeof(roman) - 1);
	    ++parts_pos) {
		part_candidate = roman_values[parts_pos];
		while (part_candidate <= num) {
			subtractible = rn_can_display_with_subtraction(num);
			if (subtractible != 0) {
				strcat(roman, rn_subtractible_roman_numeral(subtractible));
				roman_pos += 2;
				num -= subtractible;
			} else {
				roman[roman_pos++] = rn_romandigit(part_candidate);
				num -= part_candidate;
			}
		}
	}

	if (roman[0] == 0) {
		strcpy(roman, OVERFLOW);
	}
	return strdup(roman);
}