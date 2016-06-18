#include <stdlib.h>
#include <string.h>
#include "roman.h"


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

unsigned rn_toint(const char* numeral)
{
	unsigned pos;
	int *values;
	int len;

	len = strlen(numeral);
	values = (int*)calloc(len + 1, sizeof(int));

	for(pos = 0; numeral[pos]; ++pos) {
		values[pos] = rn_digit(numeral[pos]);
	}

	if (rn_isvalid(values, len) == 0) return INVALID_NUMERAL;
	return rn_sumdigits(values, len);

}
