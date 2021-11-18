#include <string>
#include <iostream>

#include "Node.h"
#include "BinaryLookupTree.h"

using namespace std;

// Constructor //
BinaryLookupTree::BinaryLookupTree()
{
	root = nullptr;
}

// Inserter functions //

// This is our main inserter function which will be exposed to the user.
void BinaryLookupTree::insert(Node* newNode)
{
	if (root == nullptr)
	{
		root = newNode;
	}
	else
	{
		insertByTitle(newNode, root);
		insertByISBN(newNode, root);
	}
}

// This is a helper function which inserts the node into the tree by title.
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
				insertByTitle(newNode, parentNode->titleRight);
		}
		else if (parNodeTitle.compare(newNodeTitle) < 0)
		{
			if (parentNode->titleLeft == nullptr)
				parentNode->titleLeft = newNode;
			else
				insertByTitle(newNode, parentNode->titleLeft);
		}
		else
		{
			cout << "Duplicate key found. Could not place new node by title " << newNodeTitle << endl;
		}
	}
}

// And this is the corresponding helper function, inserting and sorting the node by ISBN.
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
				insertByISBN(newNode, parentNode->isbnRight);
		}
		else if (parNodeISBN.compare(newNodeISBN) < 0)
		{
			if (parentNode->isbnLeft == nullptr)
				parentNode->isbnLeft = newNode;
			else
				insertByISBN(newNode, parentNode->isbnLeft);
		}
		else
		{
			cout << "Duplicate key found. Could not place new node by ISBN " << newNodeISBN << endl;
		}
	}
}

// Search functions //

// This is the recursive solution to finding a node by title.
Node* BinaryLookupTree::rFindByTitle(Node* n, const std::string& searchTerm)
{
	if (n != nullptr)
	{
		string nodeTitle = n->GetTitle();
		if (nodeTitle.compare(searchTerm) > 0)
			return rFindByTitle(n->titleRight, searchTerm);
		else if (nodeTitle.compare(searchTerm) < 0)
			return rFindByTitle(n->titleLeft, searchTerm);
		else
			return n;
	}
	return nullptr;
}

// And the corresponding recursive solution to finding a node by ISBN.
Node* BinaryLookupTree::rFindByISBN(Node* n, const std::string& searchTerm)
{
	if (n != nullptr)
	{
		string nodeISBN = n->GetISBN();
		if (nodeISBN.compare(searchTerm) > 0)
			return rFindByISBN(n->isbnRight, searchTerm);
		else if (nodeISBN.compare(searchTerm) < 0)
			return rFindByISBN(n->isbnLeft, searchTerm);
		else
			return n;
	}
	return nullptr;
}


// And because we do not want to expose the 'root' node to the user, we implement this function so that the root node and recursive lookup functions are encapsulated
Node* BinaryLookupTree::findByTitle(const std::string& searchTerm)
{
	if (root != nullptr)
	{
		return rFindByTitle(root, searchTerm);
	}
	return nullptr;
}

// More of the same except for searching by ISBN instead of Title.
Node* BinaryLookupTree::findByISBN(const std::string& searchTerm)
{
	if (root != nullptr)
	{
		return rFindByISBN(root, searchTerm);
	}
	return nullptr;
}