#include <iostream>
#include <string>

#include "Token.h"
#include "StringInterpolator.h"

using namespace std;

StringInterpolator::StringInterpolator()
{
	root = nullptr;
}
StringInterpolator::~StringInterpolator()
{
	delete root;
}

// This initial function is responsible for breaking our arguments data into parsed key-value pairs (lookup -> replacement)
// size_t argumentCount: Amount of arguments to handle
// char* args[]: Array of arguments to convert into tokens
void StringInterpolator::tokenizeArguments(size_t argumentCount, char* args[])
{
	// Token** tokens = new Token*[argCount];
	bool didError = false;

	Token* last = nullptr;
	for (int i = 0; i < argumentCount; i++)
	{
		string curArg = args[i];
		size_t argSplitPos = curArg.find('=');

		if (argSplitPos == string::npos)
		{
			cerr << "Encountered malformed argument ... " << curArg << endl << "Argument missing '=' token" << endl;
			didError = true;
		}
		else
		{
			string lookupText = curArg.substr(0, argSplitPos),
				replacementText = curArg.substr(argSplitPos + 1);

			last = (last == nullptr) ? new Token(lookupText, replacementText) : new Token(lookupText, replacementText, last);
		}
	}

	if (didError)
	{
		cerr << "Could not tokenize all arguments. See above for additional details." << endl;
	}

	root = last;
}

// This is the actual function used to interpolate the given string into its correct format (all lookup values replaced with replacement values)
// const string& input: Input string
// Token* rootToken: Head token
string StringInterpolator::interpolate(const string& input, size_t argumentCount, char* args[])
{
	if (root == nullptr)
		tokenizeArguments(argumentCount, args);

	string interpolated = input;
	if (root != nullptr)
	{
		Token* cur = root;
		while (cur != nullptr)
		{
			interpolated = cur->replace(interpolated);
			cur = cur->last;
		}
	}
	return interpolated;
}
