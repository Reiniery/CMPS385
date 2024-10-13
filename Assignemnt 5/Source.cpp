#include "bst.h"

int main() {

	NodeStru* rootNode = nullptr;

	BSTInsertion(new NodeStru(10), &rootNode);
	BSTInsertion(new NodeStru(9), &rootNode);
	BSTInsertion(new NodeStru(50), &rootNode);
	BSTInsertion(new NodeStru(2), &rootNode);
	BSTInsertion(new NodeStru(1), &rootNode);
	BSTInsertion(new NodeStru(20), &rootNode);
	BSTInsertion(new NodeStru(3), &rootNode);

	cout << " Starting inorder traversal: \n";
	inorderTraversal(rootNode);

	cout << "\ninorder trvarsal after deleting 1:\n";
	BSTDeletion(rootNode, 1);
	inorderTraversal(rootNode);

	cout << "\ninorder trvarsal after deleting 9:\n";
	BSTDeletion(rootNode, 9);
	inorderTraversal(rootNode);

	cout << "\ninorder trvarsal after deleting 20:\n";
	BSTDeletion(rootNode, 20);
	inorderTraversal(rootNode);

	

	return 0;
}