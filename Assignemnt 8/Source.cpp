#include <iostream>
#include <vector>
#include "Btree.h"
using namespace std; 

int main() {
	
	Btree tree(3);
	vector<int> insertValues = {52,81,40,33,90,85,20,38};
	cout << "B- Tree Degree:3\n Inserting 78\n";
	tree.BTreeInsert(78);
	tree.traverse();
	
	
		for (int value : insertValues) {
		cout << "\nInserting "<< value<< "\n";
		tree.BTreeInsert(value);
		tree.traverse();
	}
	
		
	return 0;
}
