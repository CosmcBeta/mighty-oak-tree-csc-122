#include "src/node.hpp"
#include "src/squirrel.hpp"

int main()
{
	Squirrel cheeks = Squirrel("Cheeks");
	Node* nodeOne = new Node(&cheeks);

	Squirrel squeaks = Squirrel("Squeaks");
	Node* nodeTwo = new Node(&squeaks);

	Squirrel fluffybutt = Squirrel("Mr. Fluffy Butt");
	Node* nodeThree = new Node(&fluffybutt);

	nodeOne->setLeft(nodeTwo);
	nodeOne->setRight(nodeThree);

	Node* retrievedNodeOne = nodeOne->left();  // This should retrieve the left node
	Node* retrievedNodeTwo = nodeOne->right(); // This should retrieve the right node

	delete nodeOne;
	delete nodeTwo;
	delete nodeThree;
}
