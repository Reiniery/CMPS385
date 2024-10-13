#include "bst.h"


//constructor for node. 
NodeStru::NodeStru(int value) {
	data = value;
	left = nullptr;
	right = nullptr;
}
//insert
void BSTInsertion(NodeStru* newNode, NodeStru** rootNode) {
	//check if root exists
	if (*rootNode == nullptr) {
		*rootNode = newNode;
	}
	//check if value is less than root
	if (newNode->data < (*rootNode)->data) {
		//if left path is empty, set newNode to leftptr
		if ((*rootNode)->left == nullptr) {
			(*rootNode)->left = newNode;
		}
		else {
			//recursion to so that it finds a left node that is null
			BSTInsertion(newNode, &((*rootNode)->left));
		}
		
	}
	//check if value is greater than root;
	else if (newNode->data > (*rootNode)->data) {
		//if right path is empty, set to new node
		if ((*rootNode)->right == nullptr) {
			(*rootNode)->right = newNode;
		}
		//recursion for the right side
		else {
			BSTInsertion(newNode, &((*rootNode)->right));
		}
	}
}
//find min;
NodeStru* findMin(NodeStru* root) {
	while(root != nullptr && root->left != nullptr){
		root = root->left;
	}
	return root;
}

//delete
NodeStru* BSTDeletion(NodeStru* rootNode, int value) {
	//empty root
	if (rootNode == nullptr) {
		return rootNode;
	}

	//value is smaller than root, go left side
	if (value < rootNode->data) {
		rootNode->left = BSTDeletion(rootNode->left, value);
	}
	//if it is greater, go ro right
	else if (value > rootNode->data) {
		rootNode->right = BSTDeletion(rootNode->right, value);
	}
	else {
		//case where there are no children
		if (rootNode->left == nullptr && rootNode->right == nullptr) {
			delete rootNode;
			return 0;
		}
		//case where there is one child
		if (rootNode->left == nullptr) {
			NodeStru* temp = rootNode->right;
			delete rootNode;
			return temp;
		}
		else if (rootNode->right == nullptr) {
			NodeStru* temp = rootNode->left;
			delete rootNode;
			return temp;
		}
		//case where there are 2 children
		NodeStru* temp = findMin(rootNode->right);  // Find minimum node in the right subtree
		rootNode->data = temp->data;  // Copy the value of the minimum node
		rootNode->right = BSTDeletion(rootNode->right, temp->data);  // Delete the minimum node
	}
	return rootNode;

}

//inorder traversla
void inorderTraversal(NodeStru* rootNode) {
	if (rootNode != nullptr) {
		inorderTraversal(rootNode->left);
		cout << rootNode->data << " ";
		inorderTraversal(rootNode->right);
	}
}
