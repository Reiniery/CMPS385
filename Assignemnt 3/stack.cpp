#include <iostream>
#include "stack.h"
using namespace std;

Stack::Stack() : stackTop(nullptr) {}

node* Stack::createStack() {
	int numOfNodes;
	node* temp = nullptr;
	// get number of nodes that will be in linked list
	cout << "How many nodes in linked list?\n";
	cin >> numOfNodes;

	//loop through each node
	for (int i = 0; i < numOfNodes; i++) {
		node* newNode = new node(i);

		//set node as index value
		newNode->next = nullptr;
		if (i == 0) {
			stackTop = newNode;
			temp = stackTop;

		}
		else {
			temp->next = newNode;
			temp = newNode;
		}

	}

	return stackTop;
}

void Stack::push(int value) {
	
	node* newNode = new node(value); //create and initialize the new node to push
	newNode->next = stackTop;//set new node next ptr to current top
	stackTop = newNode;//set the newnode as the top
}
int Stack::TopandPop() {
	if (stackTop == nullptr) {
		cout << "ERROR: List is empty";
		return -1;
	}
	else {
		node* tmp = stackTop; //set the top to tmp, we will delete this one
		stackTop = stackTop->next;//set the new stacktop to the next ptr
		delete tmp;//deallocate the tmp
		return 0;
	}
}
void Stack::print() {
	node* tmp = stackTop;
	//iterare through list th print
	while (tmp != nullptr) {
		
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
}