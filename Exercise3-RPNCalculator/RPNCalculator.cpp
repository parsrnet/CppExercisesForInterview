#include <iostream>

#include "Stack.h"
#include "RPNCalculator.h"

// Constructor function //
RPNCalculator::RPNCalculator(const char* input)
{
	stack = Stack();
	buffer = input;
	bufIndex = 0;
}

// Helper function to determine if char c is a number (0-9)
bool RPNCalculator::isNumber(char c)
{
	return (c >= '0' && c <= '9');
}

// Another helper function used to determine if char c is an operator (defined in RPNCalculator.h)
bool RPNCalculator::isOperator(char c)
{
	for (int i = 0; operators[i] != '\0'; i++)
		if (c == operators[i])
			return true;
	return false;
}

// Peek function, so that we can look at the current letter in the buffer.
char RPNCalculator::peek()
{
	return buffer[bufIndex];
}

// Next function, so that we can advance the buffer
char RPNCalculator::next()
{
	return buffer[++bufIndex];
}

// Once we encounter a number in our buffer, we can call this function to parse the full number and push the integer form onto the stack.
int RPNCalculator::parseNumber()
{
	int n = 0;
	char curChar = peek();
	while (isNumber(curChar))
	{
		n *= 10;
		int toInteger = curChar - '0';
		n += toInteger;
		curChar = next();
	}
	stack.push(n);
	return n;
}

// Like numbers, operators are important for the calculator functionality. Once we encounter an operator in the buffer, we want to pop() the two last numbers and preform a mathematical operation
//	on them, then push that result onto the stack
int RPNCalculator::parseOperator()
{
	char op = peek();
	int rhs = stack.pop(), lhs = stack.pop();

	if (op == '+')
		stack.push(lhs + rhs);
	else if (op == '-')
		stack.push(lhs - rhs);
	else if (op == '*')
		stack.push(lhs * rhs);
	else if (op == '/')
		stack.push(lhs / rhs);
	else if (op == '^')
	{
		int result = lhs;
		for (int i = 1; i < rhs; i++)
			result *= lhs;
		stack.push(result);
	}

	return stack.peek();
}

// This function will cause the calculator to run until it exhausts its buffer and return the result as an integer.
int RPNCalculator::calculate()
{
	char curChar = peek();
	while (curChar != '\0')
	{
		if (isNumber(curChar))
			int i = parseNumber();
		else if (isOperator(curChar))
			int i = parseOperator();

		curChar = next();
	}

	return stack.pop();
}