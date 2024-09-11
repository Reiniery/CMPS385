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
    //check if it is out of bounds
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
