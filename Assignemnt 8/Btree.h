#pragma once
#include <iostream>
#include <vector>
#ifndef BTREE_H
#define BTREE_H


struct BTreeNode {
	int *keys;
	BTreeNode **children;
	int numKeys;
	bool isLeaf;
	int minDegree;


	BTreeNode(int degree, bool leafStatus);
	bool BTreeNodeSearch(int value);
	void insertNotFull(int key);
	void splitChild(int index, BTreeNode* fc);
	void traverse();

};
class Btree {
private: 
	
	BTreeNode* root;
	int minDegree;

public:
	Btree(int degree): root(nullptr), minDegree(degree){}
	void traverse();
	void BTreeInsert(int x);

};

#endif