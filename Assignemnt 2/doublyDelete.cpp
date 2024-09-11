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
