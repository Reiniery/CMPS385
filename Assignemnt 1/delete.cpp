//name: Reiniery Villalta

//function to delete node in linked list

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
