#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roman.h"
#include "roman_convert.h"

#define BUFFER_LENGTH 20

static const unsigned RN_MAX = 3999;

char* rn_add(const char *lhs, const char *rhs)
{
	unsigned ilhs;
	unsigned irhs;
	unsigned sum;
	static char buffer[BUFFER_LENGTH];

	if (NULL == lhs) return NULL;
	if (NULL == rhs) return NULL;
	ilhs = rn_toint(lhs);
	irhs = rn_toint(rhs);

	memset(buffer, 0, BUFFER_LENGTH);

	sum = ilhs + irhs;
	if (sum > RN_MAX) {
		strncpy(buffer, OVERFLOW, BUFFER_LENGTH);
	} else {
		rn_toroman(ilhs + irhs, buffer, BUFFER_LENGTH);
	}
	return buffer;
}

char* rn_subtract(const char *lhs, const char *rhs)
{
	unsigned ilhs;
	unsigned irhs;
	static char buffer[BUFFER_LENGTH];

	if (NULL == lhs) return NULL;
	if (NULL == rhs) return NULL;
	ilhs = rn_toint(lhs);
	irhs = rn_toint(rhs);

	memset(buffer, 0, BUFFER_LENGTH);

	rn_toroman(ilhs - irhs, buffer, BUFFER_LENGTH);
	return buffer;
}
