#include <stdlib.h>
#include <stdio.h>
#include "roman_app.h"

int main(int argc, char **argv)
{
	char operator;
	char *lhs;
	char *rhs;

	if (argc != 4) {
		fprintf(stderr, "usage: %s ROMAN_NUMERAL [+-] ROMAN_NUMERAL\n",
			       	argv[0]);
		return EXIT_FAILURE;
	}

	lhs = argv[1];
	rhs = argv[3];
	operator = argv[2][0];

	if (operator != '-' && operator != '+') {
		fprintf(stderr, "Error: operator must be + or -\n");
		return EXIT_FAILURE;
	}

	printf("%s\n", calculate(lhs, operator, rhs));

	return EXIT_SUCCESS;
}
