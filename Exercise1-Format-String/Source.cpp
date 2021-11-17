#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstdarg>
#include <string>

#include "Token.h"

// By Joshua M. Willis //

/*
	Hello! I created this program and other exercises in order to show my
	understanding of the C and C++ programming languages. Please pay attention
	to my comments as they will explain my reasoning and conclusions at various times
	throughout this project.

	I would like to thank my former co-worker, Phil Goldfarb, for creating and sharing 
	these exercises with me in the first place. He in no way helped to provide
	a solution. All of the following work is my [Joshua M. Willis'] own.


	For this project, I am going to make a string interpolation engine and attempt
	to avoid using container objects, such as std::vector, std::list, and std::queue.
	I will annotate my code with possible optimizations using the container objects,
	but I am avoiding their use to show flexibility and my understanding of core
	programming structures.

	The string interpolation engine will take in 
	a string of any length > 0 for the unformatted string,
	and another string of any length >= 0 for the parameters.

	The parameter's syntax should be as such: "lookupText=replacementText"

	The interpolation engine must parse and replace all instances of the lookupText with the
	corresponding replacementText.

	Here, I implement a standard reverse linked node list, where the nodes are called Tokens which hold a look-up key value and a replacement value.
		If I were not to constrain myself by avoiding premade container objects, I would simply use a lookup dictionary.
*/

using namespace std;

Token* tokenizeArguments(size_t argumentCount, char* args[])
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
			cerr << "Encountered malformed argument ... " << curArg << endl;
			cerr << "Argument missing = token" << endl;
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

	return last;
}

string interpolateString(const string& input, Token* rootToken)
{
	string interpolated = input;
	if (rootToken != nullptr)
	{
		Token* cur = rootToken;
		while (cur != nullptr)
		{
			interpolated = cur->replace(interpolated);
			cur = cur->last;
		}
	}
	return interpolated;
}


int main(int argc, char* argv[])
{
	/*
		argv[0] = Program
		argv[1] = Text to Interpolate
		argv[2 ... argc - 1] = Parameters

		There are three main cases:
			argc > 2: User inputted more than one argument - attempt to parse.

			argc == 2: User inputted single argument. We assume no formatting. Show unmodified entry.

			Logically, anything else would be argc == 1: User submitted no command line arguments. 
	*/

	if (argc > 2)
	{
		int argumentCount = argc - 2;
		// In the following line, we use (argv + 2) to denote the array argv starting two indices ahead of the 0th index
		char** arguments = (argv + 2);
		Token* rootToken = tokenizeArguments(argumentCount, arguments);

		char* unformattedString = argv[1];
		string interpolated = interpolateString(unformattedString, rootToken);

		cout << interpolated << endl;
	}
	else if (argc == 2)
	{
		cout << argv[1] << endl;
	}
	else
	{
		cout << "Not enough command line arguments to parse interpolated string." << endl;
	}

	cout << "Press any key to end program..." << endl;
	getchar();

	return 0;
};