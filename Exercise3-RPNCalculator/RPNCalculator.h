#pragma once

class RPNCalculator
{
protected:
	Stack stack;
	const char* buffer;
	unsigned int bufIndex;

	const char* operators = "+-*/^";

	int parseNumber();
	int parseOperator();

	char peek();
	char next();

	bool isNumber(char c);
	bool isOperator(char c);

public:
	RPNCalculator(const char* input);
	~RPNCalculator();

	int calculate();
};