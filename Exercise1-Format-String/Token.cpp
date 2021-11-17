#include <string>

#include "Token.h"

// Implements Token.h //

using namespace std;

// Default constructor.
Token::Token()
{
	lookupText = "";
	replacementText = "";
}

// Constructor
Token::Token(string lookupText, string replacementText, Token* last)
{
	this->lookupText = lookupText;
	this->replacementText = replacementText;

	this->last = last;
}

// Recursive replace function.
// Will recursively replace each instance of lookupText and replace it with replacementText
// str: String to replace instances of lookupText with replacementText
string Token::replace(string str)
{
	size_t firstPos = str.find(this->lookupText);
	if (firstPos != string::npos)
	{
		return replace(str.replace(firstPos, lookupText.length(), replacementText));
	}

	return str;
}

// Iteratively replace each of instance of lookupText with replacementText in string str
string Token::ireplace(string str)
{
	size_t firstPos = str.find(this->lookupText);
	while (firstPos != string::npos)
	{
		str = str.replace(firstPos, lookupText.length(), replacementText);
		firstPos = str.find(this->lookupText);
	}
	return str;
}