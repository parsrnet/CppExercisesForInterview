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

	I can immediately identify that a Stack structure is the most appropriate container. It gives us the ability to advance, peek, and pop.

	When we consider how an RPN calculator works, we can think of each number as an operation pushing itself onto a stack. When we encounter an operator, we will preform a function
		on the two most recent entries to the stack, one being the left-hand side and one being the right-hand side.

	Beyond that, an RPN calculator is a very simple and quick yet powerful tool when programmed correctly.
*/

using namespace std;

int main(int argc, char* argv[])
{
	Stack S = Stack();

	if (argc > 1)
	{
		RPNCalculator calc = RPNCalculator(argv[1]);

		cout << "CALCULATING " << argv[1] << endl << calc.calculate() << endl;
	}
	else
	{
		cerr << "Missing argument. Cannot calculate." << endl;
		exit(1);
	}
	cout << "Press enter to continue...";
	getchar();
	return 0;
}