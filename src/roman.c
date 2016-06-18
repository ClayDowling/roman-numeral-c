#include "roman.h"

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
		case 'D':
		default:
			return INVALID_NUMERAL;
	}
}

unsigned rn_toint(const char* numeral)
{
	return rn_digit(numeral[0]);
}
