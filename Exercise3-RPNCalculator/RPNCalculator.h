#pragma once

class RPNCalculator
{
protected:
	Stack stack;
	const char* toParse;
	unsigned int toParseIdx;

	const char* operators = "+-*/^";

	int parseNumber();
	int parseOperator();

	char peek();
	char next();

	bool isNumber(char c);
	bool isOperator(char c);

public:
	RPNCalculator(const char* input);

	int calculate();

};