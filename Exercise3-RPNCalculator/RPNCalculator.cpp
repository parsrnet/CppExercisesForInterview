#include <iostream>

#include "Stack.h"
#include "RPNCalculator.h"

RPNCalculator::RPNCalculator(const char* input)
{
	this->stack = Stack();
	this->toParse = input;
	this->toParseIdx = 0;
}

bool RPNCalculator::isNumber(char c)
{
	return (c >= '0' && c <= '9');
}

bool RPNCalculator::isOperator(char c)
{
	for (int i = 0; this->operators[i] != '\0'; i++)
		if (c == operators[i])
			return true;
	return false;
}

char RPNCalculator::peek()
{
	return this->toParse[this->toParseIdx];
}

char RPNCalculator::next()
{
	return this->toParse[++this->toParseIdx];
}

int RPNCalculator::parseNumber()
{
	int n = 0;
	char curChar = this->peek();
	while (this->isNumber(curChar))
	{
		n *= 10;
		int toInteger = curChar - '0';
		n += toInteger;
		curChar = this->next();
	}
	this->stack.push(n);
	return n;
}

int RPNCalculator::parseOperator()
{
	char op = this->peek();
	int rhs = this->stack.pop(), lhs = this->stack.pop();

	if (op == '+')
		this->stack.push(lhs + rhs);
	else if (op == '-')
		this->stack.push(lhs - rhs);
	else if (op == '*')
		this->stack.push(lhs * rhs);
	else if (op == '/')
		this->stack.push(lhs / rhs);
	else if (op == '^')
	{
		int result = lhs;
		for (int i = 1; i < rhs; i++)
			result *= lhs;
		this->stack.push(result);
	}

	return this->stack.peek();
}

int RPNCalculator::calculate()
{
	char curChar = this->peek();
	while (curChar != '\0')
	{
		if (this->isNumber(curChar))
		{
			int i = this->parseNumber();
			std::cout << "Parsing number " << i << std::endl;
		}
		else if (this->isOperator(curChar))
		{
			int i = this->parseOperator();
			std::cout << "Parsing operator " << i << std::endl;
		}

		curChar = this->next();
	}

	return this->stack.pop();
}