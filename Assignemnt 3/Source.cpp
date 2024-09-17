#include <iostream>
#include "stack.h"
using namespace std;



int main() {
	Stack stack;
	
	stack.createStack();
	stack.print();
	stack.push(3);
	cout << "\nAfter push()\n";
	stack.print();
	stack.TopandPop();
	cout << "\nAfter TopandPop()\n";
	stack.print();
	return 0;
}
