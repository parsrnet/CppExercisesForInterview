#include <string>

#include "Node.h"

using namespace std;

// Default Constructor
Node::Node(string title, string auth, string isbn)
{
	this->title = title;
	this->author = auth;
	this->isbn = isbn;

	this->titleLeft = this->isbnLeft = nullptr;
	this->titleRight = this->titleLeft = nullptr;
}

// Getters

// Get title
string Node::GetTitle()
{
	return this->title;
}

// Get author
string Node::GetAuthor()
{
	return this->author;
}

// Get ISBN
string Node::GetISBN()
{
	return this->isbn;
}