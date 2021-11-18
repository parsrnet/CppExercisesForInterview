#pragma once

class BinaryLookupTree
{
protected:
	Node* root;

	void insertByTitle(Node* newNode, Node* parentNode = nullptr);
	void insertByISBN(Node* newNode, Node* parentNode = nullptr);

	Node* rFindByTitle(Node* n, const std::string& searchTerm);
	Node* rFindByISBN(Node* n, const std::string& searchTerm);

public:
	BinaryLookupTree();
	~BinaryLookupTree();

	void insert(Node* newNode);

	Node* findByTitle(const std::string& searchTerm);
	Node* findByISBN(const std::string& search);
};