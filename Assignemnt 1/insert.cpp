//name: Reiniery Villalta

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
