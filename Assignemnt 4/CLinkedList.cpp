#include <iostream>
#include "CLinkedList.h"
using namespace std;

queueNode* CLinkedList::createCList() {
	int numOfNodes;
	
	// get number of nodes that will be in linked list
	cout << "How many nodes in linked list?\n";
	cin >> numOfNodes;
	
	queueNode* temp = nullptr;
	//loop through each node
	for (int i = 0; i < numOfNodes; i++) {
		queueNode* newNode = new queueNode(i);

		//set node as index value
		
		if (i == 0) {
			
			backPtr = newNode;
			backPtr->next = backPtr;
			temp = backPtr;

		}

		else {
			backPtr->next = newNode;
			backPtr = newNode;
		}
		if (i == numOfNodes - 1) {
			backPtr->next = temp;
		}

	}

	return backPtr;

}
void CLinkedList::print() {
	queueNode* tmp = backPtr->next;
	//iterare through list th print
	do {
		//iterare through list th print
			cout << tmp->data << " ";
			tmp = tmp->next;
	} while (tmp != backPtr->next);
	cout << endl;
}
void CLinkedList::enqueue(int newItem) {
	queueNode* newPtr = new queueNode(newItem);

	

	if (backPtr == nullptr) {
		backPtr = newPtr;
		backPtr->next = backPtr;
	}
	else {
		newPtr->next = backPtr->next;
		backPtr->next = newPtr;
		backPtr = newPtr;
	}
}
void CLinkedList::dequeue() {
	queueNode* temp = backPtr->next;
	backPtr->next = temp->next;
	temp->next = nullptr;
	delete temp;
}
int CLinkedList::getFront() {
	if (backPtr == nullptr) {
		cout << "ERROR: List is empty";
	}
	else {
		queueNode* queueFront = backPtr->next;
		return queueFront->data;
	}
}