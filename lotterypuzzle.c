#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include "readint.h"

#define NUM_IN_LOTTERY 0 
#define NUM_WINNERS 1
#define NUM_TIX_PER_WIN 2
#define NUM_IN_GROUP 3


/* this is a comment */

double factorial(double x) {

	double product;
	product = 1;

	while (x > 0) {
		product *= x;
		--x;
	}

	return product;
}

unsigned long long lFactorial(unsigned long long x) {

	unsigned long long product;
	product = 1;

	while (x > 0) {
		product *= x;
		--x;
	}

	return product;
}

double sqrtFactorial(double x) {

	double product;
	product = 1;

	while (x > 0) {
		product *= sqrt(x);
		--x;
	}

	return product;
}

double nChooseK(double n, double k) {

	return factorial(n)/(factorial(k) * factorial(n - k));
}

double sqrtNChooseK(double n, double k) {

	return sqrtFactorial(n)/(sqrtFactorial(k) * sqrtFactorial(n - k));
}

int main() {

	int count;
	int* inputArray = (int*) malloc(4 * sizeof(int));
	long winsNeeded;
	long possibleWinningCombos = 0;
	long possibleCombos = 0;

	for (count = 0; count < 4; count++) {
		readInt(&inputArray[count]);
	}

	possibleCombos = nChooseK(inputArray[NUM_IN_LOTTERY], inputArray[NUM_WINNERS]);
	winsNeeded = ceil((double) inputArray[NUM_IN_GROUP] / inputArray[NUM_TIX_PER_WIN]);

	for (count = winsNeeded; count < inputArray[NUM_IN_GROUP] + 1; count++) {
		possibleWinningCombos += 
			(nChooseK(inputArray[NUM_IN_GROUP], count) * 
				nChooseK(inputArray[NUM_IN_LOTTERY] - inputArray[NUM_IN_GROUP], inputArray[NUM_WINNERS] - count));
	}

	/*
	printf("%s\t%f\t%s\t%f\t%s\t%f\n\n", "factorial: ", factorial(5), "sqrt factorial: ", sqrtFactorial(5), "sqrt factorial ^2: ", sqrtFactorial(5) * sqrtFactorial(5));
	printf("%s\t%f\t%s\t%f\t%s\t%f\n\n", "nChooseK: ", nChooseK(10, 4), "sqrt nChooseK: ", sqrtNChooseK(10, 4), "sqrt nChooseK ^2: ", sqrtNChooseK(10, 4) * sqrtNChooseK(10, 4));
	*/

	printf("%lu\n", sizeof(double));
	printf("%lu\n", sizeof(unsigned long));
	printf("%lu\n", sizeof(long));
	printf("%lu\n", sizeof(unsigned long long));

	// for (count = 1; count < 50; count++) {
	// 	printf("%s\t%d\n%s\t%.0f\n%s\t%llu\n\n", "count", count, "factorial: ", factorial(count), "l-factorial: ", lFactorial(count));
	// }


	// printf("%s\t%ld\n", "possibleWinningCombos: ", possibleWinningCombos);
	// printf("%s\t%ld\n", "possibleCombos: ", possibleCombos);
	// printf("%.11Lf\n", (long double) possibleWinningCombos / possibleCombos);

	free(inputArray);
}


