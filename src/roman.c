#include "roman.h"

static int rn_digit(char rn)
{
	switch(rn) {
		case 'I':
			return 1;
		case 'V':
			return 5;
	}
}

int rn_toint(const char* numeral)
{
	return rn_digit(numeral[0]);
}
