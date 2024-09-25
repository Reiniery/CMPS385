#ifndef CLinkedList_H
#define CLinkedList_H

struct queueNode {
	int data;
	queueNode* next;
	queueNode(int value) : data(value), next(nullptr) {};
};

class CLinkedList {
public: 
	CLinkedList() :backPtr(nullptr){}
	queueNode* createCList();
	void enqueue(int newItem);
	void dequeue();
	int getFront();
	void print();
private:
	queueNode* backPtr;
};
#endif