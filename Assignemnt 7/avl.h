#include <iostream>
#include <vector>
#pragma once
#ifndef AVL_H
#define AVL_H
//avl node build
struct AVLnode {
	int info;
	int bfactor;
	AVLnode* leftptr;
	AVLnode* rightptr;

	AVLnode(int info); //constructor to build a newn node
};

class AVLtree {
private:
	AVLnode* root;
public:

	AVLtree();

//functions to perform
int createAVL(AVLnode* T, std::vector<int> sequence);
AVLnode* insertAVL(AVLnode* T, int info);
int deleteAVL(AVLnode* T, int info);

//functions needed to support 
AVLnode* getRoot();

AVLnode* rightRotate(AVLnode* y);  
AVLnode* leftRotate(AVLnode* x);   
int height(AVLnode* N);            
int getBalance(AVLnode* N); 
void inorderTraversal(AVLnode* rootNode);
AVLnode* minValueNode(AVLnode* node);
};




#endif 
