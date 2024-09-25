#include <iostream>
#include "CLinkedList.h"
using namespace std;

int main() {
	CLinkedList cList;
	int newNode = 7;
	cList.createCList();
	cList.print();
	cList.enqueue(newNode);
	cout << "AFTER ENQUEUE\n";
	cList.print();
	cList.dequeue();
	cout << "AFTER DEQUEUE\n";
	cList.print();
	cout << "GET FRONT\n";
	int front = cList.getFront();
	cout << "Front: " << front;
	return 0;
}