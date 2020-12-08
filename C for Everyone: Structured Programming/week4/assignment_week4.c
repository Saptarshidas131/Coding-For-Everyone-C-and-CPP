/*
Coursera
Structured Programming
Week 4
Assignment - Option 2 (Natural or Social Science Focus) 
Read a single line of rationals from a file and find the sum and average 
*/

// Allows Visual Studio to use fopen and fscanf instead of fopen_s and fscanf_s
#define _CRT_SECURE_NO_WARNINGS

// Import libraries 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define the max number of pairs 
#define NUM_PAIRS 100


// Define struct that defines the rational 
typedef struct rationals {
	double numerator;
	double denominator;
} rationals;


// Add rationals
double add(rationals* a, int pair1, int pair2) {
	double sum = 0.0;
	sum = (a[pair1].numerator / a[pair1].denominator) + (a[pair2].numerator / a[pair2].denominator);
	return sum;
}

// Multiply rationals
double multiple(rationals* a, int pair1, int pair2) {
	double product = 0.0;
	product = (a[pair1].numerator / a[pair1].denominator) * (a[pair2].numerator / a[pair2].denominator);
	return product;
}

// Subtract rationals
double subtract(rationals* a, int pair1, int pair2) {
	double sub = 0.0;
	sub = (a[pair1].numerator / a[pair1].denominator) - (a[pair2].numerator / a[pair2].denominator);
	return sub;
}

// Divide rationals
double divide(rationals* a, int pair1, int pair2) {
	double div = 0.0;
	div = (a[pair1].numerator / a[pair1].denominator) / (a[pair2].numerator / a[pair2].denominator);
	return div;
}


int main() {

	FILE* file_pointer;               // File pointer 
	rationals pairs[NUM_PAIRS];       // Struct array to store rationals 
	int num_integers[NUM_PAIRS * 2];  // Store integers from file 
	int integer = 0;                  // int to iterate through integer pairs 
	int total_pairs[1];               // Store the total number of pairs in the file 
	double sum = 0.0, average = 0.0;  // sum and average of rationals as requested from the assignment

	// Open and read the grades file 
	file_pointer = fopen("integer_pairs.txt", "r");

	// Get the total number of pairs by reading the first integer
	fscanf(file_pointer, "%d", &total_pairs[0]);
	integer++;

	// Scan each integer and alternate between numerator and denominator assignment
	for (int i = 0; i < (total_pairs[0] * 2); i++) {
		// Get numerator
		fscanf(file_pointer, "%d", &num_integers[integer]);
		pairs[i].numerator = num_integers[integer];
		integer++;

		// Get denominator
		fscanf(file_pointer, "%d", &num_integers[integer]);
		pairs[i].denominator = num_integers[integer];
		integer++;
	}

	// Sum of all rationals in the file using the "add()" subroutine
	for (int i = 0; i < total_pairs[0]; i = i + 2) {
		// Account for odd number of pairs
		if ((i + 1) == total_pairs[0]) {
			sum = sum + (pairs[i].numerator / pairs[i].denominator);
			break;
		}

		sum = sum + add(pairs, i, i + 1);
	}

	// Average of all rationals 
	average = sum / total_pairs[0];

	// Print the results 
	printf("Sum of all rationals in the file: %lf\n", sum);
	printf("Average of all rationals in the file: %lf\n", average);

	return 0;
}
