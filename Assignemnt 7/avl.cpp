#include <iostream>
#include <algorithm>
#include <vector>
#include "avl.h"
using namespace std;

//Constructor for AVL NODE
AVLnode::AVLnode(int value) {
	info = value;
	leftptr = nullptr;
	rightptr = nullptr;
	bfactor = 0;
}
//contrictor for AVLtree
AVLtree::AVLtree() {
	root = nullptr;
}

//Function to perfrom
int AVLtree::createAVL(AVLnode* T, vector<int> sequence){
	//will take sequence form paramter and create nodes.
	for (int value : sequence) {
		root = insertAVL(root, value);
	}
	return 0;
}
AVLnode* AVLtree::insertAVL(AVLnode* T, int info) {


	//check if node is empty
	if (T == nullptr) {
		return new AVLnode(info);
	}
	if (info < T->info) {
		T->leftptr = this->insertAVL(T->leftptr, info);
	}
	else if (info > T->info) {
		T->rightptr = this->insertAVL(T->rightptr, info);
	}
	else {
		//If there are to of the same T->info values, throw error
		cout << "ERROR: DUPLICATE NODE\n";
		return T;
	}
	//Calculate bfactor
	int balance = this->height(T->leftptr) - this->height(T->rightptr);
	//Rotations if imbalanced
	//case 1: LL rotation
	if (balance > 1 && info < T->leftptr->info) {
		return this->rightRotate(T);
	}
	//case 2: RR rotation needed
	if (balance<-1 && info > T->rightptr->info) {
		return this->leftRotate(T);
	
	}
	//case 3: LR rotation
	if (balance > 1 && info < T->leftptr->info) {
		T->leftptr = leftRotate(T->leftptr);
		return this->rightRotate(T);
	}
	//case 4: RL rotation
	if (balance < -1 && info < T->rightptr->info) {
		T->rightptr = this->rightRotate(T->rightptr);
		return this->leftRotate(T);
	}

	return T;
}
int AVLtree::deleteAVL(AVLnode* T, int info) {
	//case where t->info cannot be found
	\
	if (T == nullptr) {
		cout << "\nERROR: Nod Value not found. AVL tree remians unchanged\n";
		return -1;
	}
	//if info is less than node value
	if (info < T->info) {
		return deleteAVL(T->leftptr,info);
	}
	//if info is bigger than node value
	else if (info > T->info) {
		return deleteAVL(T->rightptr, info);
	}
	//found the node
	else {
		//case where there is either one child or no childe
		if (T->leftptr == nullptr || T->rightptr == nullptr) {
			//check if either left ptr ot right ptr exists
			AVLnode* temp = T->leftptr ? T->leftptr : T->rightptr;

			//no child node
			if (temp == nullptr) {
				//assign temp variable to and disconnect from tree
				temp = T;
				T = nullptr;
			}
			//one child node
			else {
				//copy the non empty value and set as T
				*T = *temp;
			}
			delete temp;
		}
		//2 children node
		else {
			AVLnode* temp = this->minValueNode(T->rightptr);
			T->info = temp->info;
			deleteAVL(T->rightptr, temp->info);
		}
	}
	//delete was succesful
	if (T == nullptr) {
		return 0;
	}
	//check if balance is right
	int balance = height(T->leftptr) - height(T->rightptr);

	//check if it is balanced and apply a rotation if needed
	//case 1: LL
	if (balance > 1 && height(T->rightptr) >= height(T->leftptr->rightptr)) {
		T = rightRotate(T);
	}
	//case 2: RR
	if (balance < -1 && height(T->rightptr->rightptr) >= height(T->rightptr->leftptr)) {
		T = leftRotate(T);
	}
	//case 3: LR
	if (balance > 1 && height(T->leftptr->rightptr) > height(T->leftptr->leftptr)) {
		T->leftptr = leftRotate(T->leftptr);
		T = rightRotate(T);
	}
	//cas4 : RL
	if (balance < -1 && height(T->rightptr->leftptr) > height(T->rightptr->rightptr)) {
		T->rightptr = rightRotate(T->rightptr);
		T = leftRotate(T);
	}
	return 0;
}
//functions needed to handle balance and rotation

//right rotation
AVLnode* AVLtree::rightRotate(AVLnode* n) {
	AVLnode* x = n->leftptr;
	AVLnode*  T2 = x->rightptr;

	//rotation
	x->rightptr = n;
	n->leftptr = T2;

	return x;
}

//left rotation
AVLnode* AVLtree::leftRotate(AVLnode* n) {
	AVLnode* x= n->rightptr;
	AVLnode* T2 = x->leftptr;


	//rotation
	x->leftptr = n;
	n->rightptr = T2;

	return x;
}


int AVLtree::height(AVLnode* N) {
	//Empty Node
	if (N == nullptr) {
		return 0;
	}
	
	return 1 + max(height(N->leftptr), height(N->rightptr));
}


AVLnode* AVLtree::getRoot() {
	return root;
}
void AVLtree::inorderTraversal(AVLnode* rootNode) {
	if (rootNode != nullptr) {
		inorderTraversal(rootNode->leftptr);
		cout << rootNode->info << " ";
		inorderTraversal(rootNode->rightptr);
	}
}
AVLnode* AVLtree::minValueNode(AVLnode* node) {
	AVLnode* current = node;
	while (current && current->leftptr != nullptr) {
		current = current->leftptr;
	}
	return current;
}