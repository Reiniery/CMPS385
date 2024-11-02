#include "Btree.h"
#include <iostream>
using namespace std;
BTreeNode::BTreeNode(int degree, bool leafStatus) {
	minDegree = degree;
	isLeaf = leafStatus;
	keys = new int[2 * minDegree - 1];
	children = new BTreeNode * [2 * minDegree];
	numKeys = 0;

	for (int i = 0; i < 2 * minDegree; i++) {
		children[i] = nullptr;
	}
}
//search function
bool BTreeNode::BTreeNodeSearch(int value) {
	int i = 0;
	while (i<numKeys && value>keys[i]) {
		i++;
	}
	//return true if found
	if ((i < numKeys && value == keys[i])) {
		return true;
	}
	//leaf
	if (isLeaf) {
		return false;
	}

	return children[i]->BTreeNodeSearch(value);

}
void BTreeNode::traverse() {
	int i;
	for (i = 0; i < numKeys; i++) {
		if (!isLeaf) {
			children[i]->traverse();
		}
		cout << keys[i] << " ";
	}
	if (!isLeaf) {
		children[i]->traverse();
	}
}
void BTreeNode::insertNotFull(int x) {
	int i = numKeys - 1;
	//node is a leaf
	if (isLeaf) {
		//make space for new node
		while (i >= 0 && keys[i] > x) {
			keys[i + 1] = keys[i];
			i--;
		}
		keys[i + 1] = x;
		numKeys++;
	}
	else {
		while (i >= 0 && keys[i] > x) {
			i--;
		}
		i++;
		//full node
		if (children[i]->numKeys == 2 * minDegree - 1) {
			splitChild(i, children[i]); 
			//insert key into child
			if (keys[i] < x) {
				i++;
			}
		}
		children[i]->insertNotFull(x);

	}
}
void BTreeNode::splitChild(int index, BTreeNode* fc) {

	BTreeNode* newChild = new BTreeNode(fc->minDegree, fc->isLeaf);
	newChild->numKeys = minDegree - 1;

	//move last keys from fc to newchild
	for (int i = 0; i < minDegree-1; i++) {
		newChild->keys[i] = fc->keys[i + minDegree];
	}
	//not a leaf, move ALL children
	if (!fc->isLeaf) {
		for (int i = 0; i < minDegree; i++) {
			newChild->children[i] = fc->children[i + minDegree];
		}
	}
	//change num of keys
	fc->numKeys = minDegree - 1;

	//make space for new child
	for (int i = numKeys; i >= index + 1; i--) {
		keys[i + 1] = keys[i];
	}
	children[index + 1] = newChild;
	// move middle key up from first child
	for (int j = numKeys - 1; j >= index; j--) {
		keys[j + 1] = keys[j];
	}
	keys[index] = fc->keys[minDegree - 1];
	numKeys++;


}

void Btree::BTreeInsert(int x) {
	//empty root
	if (root == nullptr) {
		root = new BTreeNode(minDegree, true);
		root->keys[0] = x;
		root->numKeys++;

	}
	else {
		//value is already in key
		if (root->BTreeNodeSearch(x)) {
			cout << "ERROR: Value already exists in Tree\n";
			return;
		}


		//full root
		if (root->numKeys == 2 * minDegree - 1) {
			BTreeNode* newRoot = new BTreeNode(minDegree, false);
			newRoot->children[0] = root;
			newRoot->splitChild(0, root);

			//new Key for childen
			int i = 0;
			if (newRoot->keys[0] < x) {
				i++;
			}
			newRoot->children[i]->insertNotFull(x);
			root = newRoot;
		}
		//non full root
		else {
			root->insertNotFull(x);
		}
	}
}
void Btree::traverse() {
	if (root != nullptr) {
		root->traverse();
	}
}