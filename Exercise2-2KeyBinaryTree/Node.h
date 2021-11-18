#pragma once

class Node {
protected:
	std::string title, author, isbn;

public:
	Node* titleLeft, * titleRight, * isbnLeft, * isbnRight;

	Node(std::string title, std::string auth, std::string isbn);
	~Node();
	
	// Getters
	std::string GetTitle();
	std::string GetAuthor();
	std::string GetISBN();
};