#include <iostream> 
using namespace std;


struct node {
	int data;
	node* next;
	node* prev;
};

node* create_doubly_list() {
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
		//create the first node
		if (i == 0) {
			head = newNode;
			temp = head;
			newNode->prev = nullptr;

		}
		//create the nodes that follow
		else {
			temp->next = newNode;
			newNode->prev = temp;
			temp = newNode;
		}

	}

	return head;

}


int doublyInsert(int data, int index, node*& ptr) {
	if (index < 0) {
		cout << "ERROR: index must be positive\n";
		return -1;
	}
	//create a node
	node* newNode = new node();
	newNode->data = data;
	//insert at frnt of list
	if (index == 0) {
		//left to tight (outside)
		newNode->prev = nullptr;
		newNode->next = ptr;
		//set org 1st prev ptr to new ptr
		if (ptr != nullptr) {
			ptr->prev = newNode;
		}
		//make the newnode the head
		ptr = newNode;
		return 0;
	}
	else if (index > 0) {
		cout << "Insert at Index: " << index << endl;
		node* temp = ptr;
		//stop at 1 beofre index we want to be at
		for (int i = 1; i <= index - 1; i++) {
			//will keep looping until location is found
			temp = temp->next;
		}
		if (temp == nullptr) {
			cout << "\nERROR: index Out of Bounds\n";
			delete newNode;
			return -1;
		}
		//set prev ptr to index before
		newNode->prev = temp;
		//set next ptr to ptr after index we stopped at
		newNode->next = temp->next;
		//check if the variable we stopped at was the last variable
		if (temp->next != nullptr) {
			temp->next->prev = newNode;
			
		}
		temp->next = newNode;
		return 0;






	}
	else {
		cout << "ERROR: Enter a value equal or greather than 0";
		return -1;
	}
}
int doublyDelete(int index, node*& ptr) {
	//check if list is empty
	if (ptr == nullptr) {
		cout << "ERROR: List is empty";
		return -1;
	}
	//check if index is negative
	if (index < 0) {
		cout << "ERROR: Index must be greater or equal to zero\n";
		return -1;
	}

	//deleting the first node in list
	if (index == 0) {
		node* temp = ptr;
		ptr = ptr->next;//move head of linked list to next
		if (ptr != nullptr) {//check if it exists
			ptr->prev = nullptr;//set ptr to prev null
		}
		delete temp;

	}
	//traverse through list
	else {
		node* current = ptr;
		//get to node beofre targt we want to delete
		for (int i = 0; i < index - 1; i++) {
			if (current == nullptr) {
				cout << "ERROR OUT OF BOUNDS";
				return -1;
			}
			//go to next node
			current = current->next;
		}
		//check to see if we went out of bound
		if (current == nullptr || current->next == nullptr) {
			cout << "ERROR: index of bounds\n";
			return -1;
		}
		//set the follwing index to tmp, it will be deleted
		node* temp = current->next;
		current->next = temp->next; //current next ptr will be set to the node that follows tmp
		if (temp->next != nullptr) {
			temp->next->prev = current;//set the prev ptr of the node that follow sthat one to be deleted to the node beofre the tmp
			
		}
		delete temp;//delete target node;
	}
	cout << "\nDeleted index: " << index << endl;
	return 0;
}
int main() {
	node* list = create_doubly_list();

	// view list 
	node* temp = list;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}

	//insert function
	cout << "\n-------Doubly Insert Function----------\n";
	int result = doublyInsert(5, 5, list);
	//display
	if (result == 0) {
		temp = list;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	//delere function 
	cout << "\n-----------------Delete Function--------------\n";
	int deleteResult = doublyDelete(5, list);
	//display 
	if (deleteResult == 0) {
		temp = list;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	return 0;
}