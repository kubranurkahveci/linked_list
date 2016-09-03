#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "linked.h"


int main (int argc, char **argv)
{
	BigInt p;
	BigInt d;
	BigInt b;

	char *array1; //char array1[LENGTH]
	char *array2;
	int i;

	init (&d);
	array1 = argv[1];

	for (i = strlen(array1)-1; i >= 0; i--) {
		append_digit(&d, array1[i]-'0');
	}
	print(d);
	printf("\n");

	init (&p);
	array2 = argv[2];

	for (i = 0; i < strlen(array2); i++) {
		prepend_digit(&p, array2[i]-'0');
	}
	print(p);
	printf("\n");

	BigInt x;
	add(d, p, &x);
	print(x);
	printf("\n");
	return 0;
}
