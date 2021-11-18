#include <string>

#include "Node.h"

using namespace std;

// Default Constructor
Node::Node(string _title, string _author, string _isbn)
{
	title = _title;
	author = _author;
	isbn = _isbn;

	titleLeft = isbnLeft = nullptr;
	titleRight = titleLeft = nullptr;
}

// Default destructor
Node::~Node()
{
	if (titleLeft)
		delete titleLeft;
	if (titleRight)
		delete titleRight;
}

// Getters

// Get title
string Node::GetTitle()
{
	return title;
}

// Get author
string Node::GetAuthor()
{
	return author;
}

// Get ISBN
string Node::GetISBN()
{
	return isbn;
}