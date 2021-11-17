#pragma once

class BinaryLookupTree
{
protected:
	Node* root;

	void insertByTitle(Node* newNode, Node* parentNode = nullptr);
	void insertByISBN(Node* newNode, Node* parentNode = nullptr);

	Node* rFindByTitle(Node* n, const std::string& searchTerm);
	Node* rFindByISBN(Node* n, const std::string& searchTerm);

	void print(Node* n);

public:
	BinaryLookupTree();

	void insert(Node* newNode);

	void print();

	Node* findByTitle(const std::string& searchTerm);
	Node* findByISBN(const std::string& search);
};