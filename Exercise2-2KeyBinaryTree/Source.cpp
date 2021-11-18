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
	The basis of any binary search tree is as follows:
		* Nodes have two pointers - a 'left' direction and a 'right' direction
		* The tree must deterministically compare nodes and move in either the left or right direction.
	The first point is easily fulfilled. We use the "string::compare" function to determine whether to travel in the left or right direction when inserting a new node.
	To traverse back down the tree and find these nodes, I simply follow the same rules and traverse the tree until we find a match or hit the end of the tree.
	
	To expand on the traditional binary search tree, I've included four pointers: Instead of just left or right, we have isbnLeft, isbnRight, titleLeft, and titleRight
	which are sorted independently. The tree handles inserting for both the ISBN and the Title and our insert function complexity is doubled.

	If we wanted to expand additionally on top of this, we easily could. We would simply need to include another function in the tree to insert by the third key and modify the Node
	class to have pointers for a third key.

*/

using namespace std;

int main(int argc, char* argv[])
{
	BinaryLookupTree library = BinaryLookupTree();

	library.insert(new Node("Child of God", "Cormac McCarthy", "abc123"));
	library.insert(new Node("Blood Meridian", "Cormac McCarthy", "abc124"));
	library.insert(new Node("The Raven", "Edgar Allan Poe", "cba321"));
	library.insert(new Node("Child of God 2", "Cormac McCarthy", "abc125"));
	library.insert(new Node("Love Letters to the Dead", "Ava Dellaria", "ccc333"));
	library.insert(new Node("Testbooktitle", "Testauthor", "Testisbn"));

	Node* search = library.findByTitle("Love Letters to the Dead");
	Node* search2 = library.findByISBN("Testisbn");

	if (search)
		cout << "FOUND : " << search->GetTitle() << " by " << search->GetAuthor() << " (ISBN" << search->GetISBN() << ")" << endl;

	if (search2)
		cout << "FOUND : " << search2->GetTitle() << " by " << search2->GetAuthor() << " (ISBN" << search2->GetISBN() << ")" << endl;

	return 0;
}