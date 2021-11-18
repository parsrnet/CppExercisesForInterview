#pragma once

class StringInterpolator
{
private:
	Token* root;

	void tokenizeArguments(size_t argCount, char* args[]);
public:
	StringInterpolator();
	~StringInterpolator();

	std::string interpolate(const std::string& inputString, size_t argCount, char* args[]);
};