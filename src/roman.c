#include <stdlib.h>
#include <string.h>
#include "roman.h"

static int roman_values[] = {500, 100, 50, 10, 5, 1};
int roman_values_len = sizeof(roman_values) / sizeof(int);

static int is_appear_many(unsigned digit)
{
	switch(digit) {
	case 1:
	case 10:
	case 100:
		return 1;
	default:
		return 0;
	}
}

static int should_subtract(unsigned left, unsigned right)
{
	if (left < right) return 1;
	return 0;
}

static int rn_isvalid(int *candidate, int len)
{
	int repeats = 0;
	int norepeats = 0;
	int i;

	for(i = 0; i < len; ++i) {
		if (is_appear_many(candidate[i])) {
			repeats++;
			norepeats = 0;
			if (repeats > 3) return 0;
		} else {
			if (repeats > 1 && candidate[i-1] < candidate[i])
				return 0;
			repeats = 0;
			norepeats++;
			if (norepeats > 1) return 0;
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
		default:
			return '\0';
	}
}

static unsigned rn_sumdigits(int *digits, int size)
{
	int i;
	int total = 0;

	for(i=0; i < size; ++i) {
		if (0 == digits[i]) {
			return INVALID_NUMERAL;
		}
		if (should_subtract(digits[i], digits[i+1]))
			total -= digits[i];
		else 
			total += digits[i];
	}

	if (total < 1) return INVALID_NUMERAL;
	return (unsigned)total;
}

static int rn_can_display_with_subtraction(int target)
{
	int subtractible[] = {400, 90, 40, 9, 4};
	int blocker[]      = {500, 100,50, 10, 5};
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
		strcpy(roman, "NaN");
	}
	return strdup(roman);
}

char* rn_add(const char *lhs, const char *rhs)
{
	unsigned ilhs;
	unsigned irhs;
	unsigned sum;

	if (NULL == lhs) return NULL;
	if (NULL == rhs) return NULL;
	ilhs = rn_toint(lhs);
	irhs = rn_toint(rhs);

	return rn_toroman(ilhs + irhs);
}
