#include <string>
#include <iostream>
#include <cstdlib>

#include "Node.h"
#include "BinaryLookupTree.h"

using namespace std;

// Constructor functions //
BinaryLookupTree::BinaryLookupTree()
{
	this->root = nullptr;
}

// Helper functions //
void BinaryLookupTree::print(Node* n)
{
	if (n != nullptr)
	{
		printf("TITLE: %s | AUTH: %s | ISBN: %s\n",
			n->GetTitle().c_str(), n->GetAuthor().c_str(), n->GetISBN().c_str());

		if (n->isbnLeft != nullptr)
		{
			printf("LEFT> ");
			this->print(n->isbnLeft);
		}

		if (n->isbnRight != nullptr)
		{
			printf("RIGHT> ");
			this->print(n->isbnRight);
		}
	}
}

void BinaryLookupTree::print()
{
	if (this->root != nullptr)
		this->print(this->root);
}

// Inserter functions //
void BinaryLookupTree::insert(Node* newNode)
{
	if (this->root == nullptr)
	{
		this->root = newNode;
	}
	else
	{
		this->insertByTitle(newNode, root);
		this->insertByISBN(newNode, root);
	}
}

void BinaryLookupTree::insertByTitle(Node* newNode, Node* parentNode)
{
	if (parentNode != nullptr)
	{
		string newNodeTitle = newNode->GetTitle(),
			parNodeTitle = parentNode->GetTitle();
		if (parNodeTitle.compare(newNodeTitle) > 0)
		{
			if (parentNode->titleRight == nullptr)
				parentNode->titleRight = newNode;
			else
				this->insertByTitle(newNode, parentNode->titleRight);
		}
		else if (parNodeTitle.compare(newNodeTitle) < 0)
		{
			if (parentNode->titleLeft == nullptr)
				parentNode->titleLeft = newNode;
			else
				this->insertByTitle(newNode, parentNode->titleLeft);
		}
		else
		{
			cout << "Duplicate key found. Could not place new node by title " << newNodeTitle << endl;
		}
	}
}

void BinaryLookupTree::insertByISBN(Node* newNode, Node* parentNode)
{
	if (parentNode != nullptr)
	{
		string newNodeISBN = newNode->GetISBN(),
			parNodeISBN = parentNode->GetISBN();
		if (parNodeISBN.compare(newNodeISBN) > 0)
		{
			if (parentNode->isbnRight == nullptr)
				parentNode->isbnRight = newNode;
			else
				this->insertByISBN(newNode, parentNode->isbnRight);
		}
		else if (parNodeISBN.compare(newNodeISBN) < 0)
		{
			if (parentNode->isbnLeft == nullptr)
				parentNode->isbnLeft = newNode;
			else
				this->insertByISBN(newNode, parentNode->isbnLeft);
		}
		else
		{
			cout << "Duplicate key found. Could not place new node by ISBN " << newNodeISBN << endl;
		}
	}
}

// Search functions //
Node* BinaryLookupTree::rFindByTitle(Node* n, const std::string& searchTerm)
{
	if (n != nullptr)
	{
		string nodeTitle = n->GetTitle();
		if (nodeTitle.compare(searchTerm) > 0)
			return this->rFindByTitle(n->titleRight, searchTerm);
		else if (nodeTitle.compare(searchTerm) < 0)
			return this->rFindByTitle(n->titleLeft, searchTerm);
		else
			return n;
	}
	return nullptr;
}

Node* BinaryLookupTree::rFindByISBN(Node* n, const std::string& searchTerm)
{
	if (n != nullptr)
	{
		string nodeISBN = n->GetISBN();
		if (nodeISBN.compare(searchTerm) > 0)
			return this->rFindByISBN(n->isbnRight, searchTerm);
		else if (nodeISBN.compare(searchTerm) < 0)
			return this->rFindByISBN(n->isbnLeft, searchTerm);
		else
			return n;
	}
	return nullptr;
}

Node* BinaryLookupTree::findByTitle(const std::string& searchTerm)
{
	if (root != nullptr)
	{
		return this->rFindByTitle(root, searchTerm);
	}
	return nullptr;
}

Node* BinaryLookupTree::findByISBN(const std::string& searchTerm)
{
	if (root != nullptr)
	{
		return this->rFindByISBN(root, searchTerm);
	}
	return nullptr;
}