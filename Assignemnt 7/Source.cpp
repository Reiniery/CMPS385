#include <iostream>
#include <vector>
#include "avl.h"
using namespace std; 

int main() {
	AVLtree tree;
	//sequence that will be created inside AVL tree
	vector<int> sequence = { 16, 18, 12, 17, 9, 14, 19, 15, 11, 5, 3 };

	//create avl tree
	tree.createAVL(tree.getRoot(), sequence);

	//print tree
	cout << "Inorder traversal after creating AVL:\n";
	tree.inorderTraversal(tree.getRoot());
	//insert
	cout << "\nInorder traversal after inserting 4:\n";
	tree.insertAVL(tree.getRoot(), 4);
	tree.inorderTraversal(tree.getRoot());
	//delete
	cout << "\nInorder traversal after deleting 9:\n";
	tree.deleteAVL(tree.getRoot(), 9);
	tree.inorderTraversal(tree.getRoot());
	
	return 0; 
}
