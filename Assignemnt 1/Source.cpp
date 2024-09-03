#include <iostream>
using namespace std;

//Create a Linked list
struct node {
	int data;
	node* next;
};
node* create_list() {
	int numOfNodes;
	node* temp = nullptr, * head = nullptr;
	// get number of nodes that will be in linked list
	cout << "How many nodes in linked list?\n";
	cin >> numOfNodes;

	//loop through each node
	for (int i = 0; i < numOfNodes; i++) {
		node* newNode = new node();

		//set node as index value
		newNode->data = i;
		newNode->next = nullptr;
		if (i == 0) {
			head = newNode;
			temp = head;

		}
		else {
			temp->next = newNode;
			temp = newNode;
		}

	}

	return head;
}

//function to delete node

int deleteNode(node*& data, int index) {
	//set tmp to head
	node* tmp = data;


	if (index == 0) {
		//set the next node as the new head, delete the first node afterwards
		data = tmp->next;
		delete tmp;

	}
	else {
		//loop through linked list and find the one before the target
		for (int i = 0; i < index - 1; i++) {
			tmp = tmp->next; 
		}

		node* toDelete = tmp->next;
		//check if there is a pointer after the target
		if (toDelete==nullptr) {
			cout << "ERROR\nOut of range\n ";
			return -1;
		}
		//check if there is a node after target
		else if (tmp->next->next = nullptr) {
			delete tmp->next;
			tmp->next = nullptr;
		}
		else {
			tmp->next = toDelete->next;
					delete toDelete;
		}
		
	}
	return 0;
}

//function to insert a node into linked list
//insert(linked list where you will inter the data, location of node)
int insert(node*& data, int index) {
	//head
	node* head = data;
	//create a new node
	node* newNode = new node;

	//askk for value of nodes
	cout << "Insert integer for value of node: ";
	cin >> newNode->data;


	cout << "Data for pointer\n";
	//index == 0 is add the index to the front;
	if (index == 0) {
		//set the pointer if new value to current head;
		newNode->next = data;
		//set the newNode as the headl 
		data = newNode;
	}

	else {
		//loop thriugh linked list
		for (int i = 1; i <= index; i++) {
			//will keep looping until location is found
			node* temp = data;
			data = data->next;

			//reached the end of the linked list
			if (temp->next == nullptr) {
				//if the index exist in the loop, it will add the new node;
				if (i == index) {
					temp->next = newNode;
					newNode->next = nullptr;
				}
				//if index is not in the loop, display error message ;
				else {
					cout << "ERROR: Index out of range\n";

					return -1;
				}
			}
			//will new node last in linked list
			if (i == index) {
				newNode->next = data;
				temp->next = newNode;
			}

		}
		//reset data to head
		data = head;
	}

	return 0;
}
int main() {
	//create a linked list
	node* head = create_list();

	int index;
	cout << "\n---------INSERT FUNCTION---------------\n";
	cout << "Insert Index: ";
	cin >> index;

	//int result = insert(head, index);
	node* temp = head;
	//results for inserting node
	/*
	if (result == 0) {
		cout << "New Linked List\n";
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	else {
		cout << "An Error has occured. Linked List did NOT change\n";
	}
*/
	cout << "\n----DELETE---------\n";
	cout << "Index: ";
	cin >> index; 
	//deleting Node

	int deleteResult  = deleteNode(head, index);
	if (deleteResult == 0) {
		temp = head;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	else {
		cout << "An Error has occured";
	}
	

	//will display linked list


	return 0;

}

