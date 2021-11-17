#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

#include "Node.h"
#include "BinaryLookupTree.h"

// Joshua M. Willis

/*
	For this exercise, we want to create an easily expandable function to look-up an object by different key values.
		As in, if we have a library database of books, you should be able to lookup a book in the database by both Title and ISBN.

	I quickly identify a binary search tree will be the most effective and quick structure to solve this problem.


*/

using namespace std;

int main(int argc, char* argv[])
{
	BinaryLookupTree library = BinaryLookupTree();

	library.insert(new Node("Child of God", "Cormac McCarthy", "abc123"));
	library.insert(new Node("Blood Meridian", "Cormac McCarthy", "abc124"));
	library.insert(new Node("The Raven", "Edgar Allan Poe", "cba321"));

	library.insert(new Node("Child of God 2", "Cormac McCarthy", "abc125"));

	library.print();

	Node* search = library.findByTitle("Child of God 2");

	if (search != nullptr)
		cout << "FOUND : " << search->GetTitle() << " by " << search->GetAuthor() << " (ISBN" << search->GetISBN() << ")" << endl;

	return 0;
}