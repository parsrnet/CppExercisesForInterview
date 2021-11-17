#include <iostream>
#include <string>
#include <cstdlib>

#include "Stack.h"
#include "RPNCalculator.h"
// By Joshua M. Willis

/*
	For this exercise, I am build an RPN Calculator without using any container objects.
	
	The correct syntax for an RPN calculator is as follows: 1 3 * 2 +
		Read from left to right, we have arguments and operators. In the example, we give two arguments (1 and 3) then preform an operation on them (* is multiplication), making 3.
		Following that, we encounter the next argument and next operator (2 and + [addition]). And so we take the results from the last operation and preform them thusly, (3 + 2) = 5.
		The resulting output of the string (1 3 * 2 +) should be the resulting integer of 5.

	I will only be dealing with integers initially and implementing a basic set of mathematical functions, such as addition, subtraction, multiplication, division, and raising to the nth power.

	I can immediately identify that a Stack structure is the most appropriate container. It gives us the ability to advance, peek, and pop
		


*/

using namespace std;

int main(int argc, char* argv[])
{
	Stack S = Stack();

	RPNCalculator calc = RPNCalculator("300 3 /");

	cout << calc.calculate() << endl;

	getchar();
	return 0;
}