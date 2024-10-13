
#include <iostream>
#pragma once
#ifndef BST_H
#define BST_H

using namespace std;

//each node in bst will be built this way
struct NodeStru {
	int data;
	NodeStru * right;
	NodeStru* left;

	NodeStru(int Value);// constructor to create a new node
};

//BST insertion
void BSTInsertion(NodeStru* rootNode, NodeStru** newNode);

//BST Delete
NodeStru* BSTDeletion(NodeStru* rootNode, int value);
//traversal
void inorderTraversal(NodeStru* rootNode);
//find min 
NodeStru* findMin(NodeStru* root);

#endif