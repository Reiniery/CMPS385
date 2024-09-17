#ifndef STACK_H
#define STACK_H

struct node {
	int data;
	node* next;

	node(int value): data(value), next(nullptr) {};
};

class Stack {
public: 
	Stack();
	
	node* createStack();
	void push(int value);
	int TopandPop();
	void print();
	
private: 
	node* stackTop;
};
#endif