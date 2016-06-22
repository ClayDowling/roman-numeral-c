/** 
 * Implementation of the roman calculator logic
 */
#include <stdlib.h>
#include <string.h>
#include "roman.h"

const char* calculate(const char *lhs, const char operation, const char *rhs)
{
	static char result[100];
	memset(result, 0, sizeof(result));

	if (operation == '+') {
		strncpy(result, rn_add(lhs, rhs), sizeof(result));
	}
	if (operation == '-') {
		strncpy(result, rn_subtract(lhs, rhs), sizeof(result));
	}

	return result;
}
