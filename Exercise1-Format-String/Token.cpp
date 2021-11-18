#include <string>

#include "Token.h"

// Implements Token.h //

using namespace std;

// Default constructor //
Token::Token()
{
	lookupText = "";
	replacementText = "";
	last = nullptr;
}

// Constructor //
Token::Token(string _lookupText, string _replacementText, Token* _last)
{
	lookupText = _lookupText;
	replacementText = _replacementText;

	last = _last;
}

// Destructor //
Token::~Token()
{
	if (last != nullptr)
		delete last;
}

// Recursive replace function.
// Will recursively replace each instance of lookupText and replace it with replacementText
// str: String to replace instances of lookupText with replacementText
string Token::replace(string str)
{
	size_t firstPos = str.find(lookupText);
	if (firstPos != string::npos)
	{
		return replace(str.replace(firstPos, lookupText.length(), replacementText));
	}

	return str;
}

// Iteratively replace each of instance of lookupText with replacementText in string str
string Token::ireplace(string str)
{
	size_t firstPos = str.find(lookupText);
	while (firstPos != string::npos)
	{
		str = str.replace(firstPos, lookupText.length(), replacementText);
		firstPos = str.find(lookupText);
	}
	return str;
}