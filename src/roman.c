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
			return 100;
		case 'D':
			return 500;
		default:
			return INVALID_NUMERAL;
	}
}

unsigned rn_toint(const char* numeral)
{
	int total = 0;
	char *pos = numeral;

	for(pos = numeral; *pos; ++pos) {
		total += rn_digit(*pos);
	}
	return total;
}
