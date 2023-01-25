// **********************************************************************************
// Title: CIS 111 - Project One
// Name: Gabriela Schweers
// Date: 3/30/2022
// Desc: A program, specifically a calculator, that performs addition, subtraction,
//		 division, multiplication, and modulus on two bounded integer inputs.
// **********************************************************************************

// LIBRARIES AND EXTERNAL DEPENDENCIES
#pragma warning(disable:4996) // for scanf() warnings
#include<stdio.h> // for printf(), scanf()
#include <conio.h> // for _getch()

// CONSTANTS
#define UNDEFINED ' '		// when menuChoice is undefined
#define ADDITION '+'		// menuChoice 1
#define SUBTRACTION '-'		// menuChoice 2
#define MULTIPLICATION '*'	// menuChoice 3
#define DIVISION '/'		// menuChoice 4
#define MODULUS '%'			// menuChoice 5

#define LOWERBOUND -1000	// lowest integer input allowed
#define UPPERBOUND 1000		// highest integer input allowed

// FUNCTION PROTOTYPES
void add(int, int, int&);
void subtract(int, int, int&);
void multiply(int, int, int&);
void divide(int, int);		// only takes two, does not ultilize variable 'result'
void mod(int, int, int&);

// MAIN
using namespace std;
int main() {
	// DECLARING AND INITIALIZING VARIABLES
	int intOne = 0; // holds first integer input
	int intTwo = 0; // holds second integer input
	int result = 0; /* holds result of mathematical operations, NOTE: not used for division
					due to explicit casting needed */

	char menuChoice = UNDEFINED;			// holds menuChoice
	char absorbPhantom = ' ';				// for fixing up display

	// PROMPTING FOR intOne AND intTwo INTEGER INPUTS
	printf("Please enter in integer #1: ");						// asking for first integer input
	scanf("%d%c", &intOne, &absorbPhantom);
	while ((intOne < LOWERBOUND) || (intOne > UPPERBOUND)) {	// checking if input is between bounds
		printf("Please enter in an integer between the closed interval [-1000,1000]\n");
		printf("Please enter in integer #1: ");
		scanf("%d%c", &intOne, &absorbPhantom);
	}
	
	printf("Please enter in integer #2: ");						// asking for second integer input
	scanf("%d%c", &intTwo, &absorbPhantom);
	while ((intTwo < LOWERBOUND) || (intTwo > UPPERBOUND)) {	// checking if input is between bounds
		printf("Please enter in an integer between the closed interval [-1000,1000]\n");
		printf("Please enter in integer #2: ");
		scanf("%d%c", &intTwo, &absorbPhantom);							// storing...
	}

	// MENU PROMPT
	printf("--------------------------------------------------------\n"); 
	printf("AVAILABLE OPERATIONS:\n"); 
	printf("> Addition (+)\n");
	printf("> Subtraction (-)\n");
	printf("> Multiplication (*)\n");
	printf("> Division (/)\n");
	printf("> Modulus (%%)\n");
	printf("Please type in the SYMBOL of the operation you desire: "); 
	scanf("%c%c", &menuChoice, &absorbPhantom);							// storing user input in menuChoice...

	// VALIDATION CHECKING
	while ((menuChoice != ADDITION) && (menuChoice != SUBTRACTION) && (menuChoice != MULTIPLICATION) 
		&& (menuChoice != DIVISION) && (menuChoice != MODULUS)) {
		printf("--------------------------------------------------------\n"); 
		printf("AVAILABLE OPERATIONS:\n"); 
		printf("> Addition (+)\n");
		printf("> Subtraction (-)\n");
		printf("> Multiplication (*)\n");
		printf("> Division (/)\n");
		printf("> Modulus (%%)\n");
		printf("Please type in the SYMBOL of the operation you desire: "); 
		scanf("%c%c", &menuChoice, &absorbPhantom); 
	}

	// MENU MECHANICS AND DISPLAY
	switch (menuChoice) {
		case UNDEFINED:
			printf("A choice from the menu has not been chosen...\n");
			break;
		case ADDITION:
			printf("You have chosen ADDITION\n\n");
			add(intOne, intTwo, result);		// calls addition function
			break;
		case SUBTRACTION:
			printf("You have chosen SUBTRACTION\n\n");
			subtract(intOne, intTwo, result);	// calls subtraction function
			break;
		case MULTIPLICATION:
			printf("You have chosen MULTIPLICATION\n\n");
			multiply(intOne, intTwo, result);	// calls multiply function
			break;
		case DIVISION:
			printf("You have chosen DIVISION\n\n");
			divide(intOne, intTwo);				// calls divide function
			break;
		case MODULUS:
			printf("You have chosen MODULUS\n\n");
			mod(intOne, intTwo, result);		// calls mod function
			break;
		default: 
			break;
	}

	// EXIT TO OS
	printf("Press any key to continue..."); 
	_getch();
	return 0;
}

// FUNCTION DEFINITIONS
// Addition function
void add(int intOne, int intTwo, int& result) {								// called when menuChoice = 1
	result = (intOne + intTwo);												// mathematical operations...
	printf("The sum of %d + %d is %d\n", intOne, intTwo, result);			// display result
}

// Subtraction function
void subtract(int intOne, int intTwo, int& result) {						// called when menuChoice = 2
	result = (intOne - intTwo);												// mathematical operations...
	printf("The difference of %d - %d is %d\n", intOne, intTwo, result);	// display result
}

// Multiply function
void multiply(int intOne, int intTwo, int& result) {						// called when menuChoice = 3
	result = (intOne * intTwo);												// mathematical operations...
	printf("The product of %d * %d is %d\n", intOne, intTwo, result);		// prints out result
}

// Division function
void divide(int intOne, int intTwo) {											// called when menuChoice = 4
	if (intTwo == 0) {															// making sure intTwo is not equal to 0, will not do operation if so
		printf("You cannot divide by zero. Make sure your second integer value is > 0 if choosing division.\n"); 
	} else {
		double result = ((double)intOne / (double)intTwo);						// LOCAL VAR RESULT FOR EXPLICIT CASTING, mathematical operations...
		printf("The quotient of %d / %d is %.4f\n", intOne, intTwo, result);	// prints out result
	}
}

// Modulus function
void mod(int intOne, int intTwo, int& result) {									// called when menuChoice = 5
	if (intTwo == 0) {															// can't mod by 0 in C/C++. if intTwo == 0, operation will not be performed
		printf("C++ does not enable mod 0 operations, and is undefined. Make sure your second integer value is > 0 if choosing modulus.\n");
	} else {
		result = (intOne % intTwo);												// mathematical operations...
		printf("The remainder of %d %% %d is %d\n", intOne, intTwo, result);	// prints out result
	}
}