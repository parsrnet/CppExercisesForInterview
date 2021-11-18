#pragma once

// We use a class here to take advantage of C++'s changes from C
//	We could effectively use a struct, but it makes more practical sense to use a class
//	which will allow us to define a member method and avoid having 
//	to refactor our code in the future if a class becomes necessary. (OOP)

class Token
{
	std::string lookupText;
	std::string replacementText;

public:
	Token* last;

	Token();
	Token(std::string _lookupText, std::string _replacementText, Token* last=nullptr);

	std::string replace(std::string str);
	std::string ireplace(std::string str);
};