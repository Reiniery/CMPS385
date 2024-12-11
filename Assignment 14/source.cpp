
#include <iostream>
#include <vector>
using namespace std;

//merge sort
void merge(vector<int>& a, vector<int>& b, int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;
	//merge two arrays
	while (i <= mid && j <= right) {
		if (a[i] <= a[j]) {
			b[k] = a[i];
			i++;
		}
		else {
			b[k] = a[j];
			j++;
		}
		k++;
	}
	//copy elements of left array
	while (i <= mid) {
		b[k] = a[i];
		i++;
		k++;
	}
	//copy elements of right array
	while (j <= right) {
		b[k] = a[j];
		j++;
		k++;
	}
}
void copy(vector<int>& b, vector<int>& a, int left, int right) {
	for (int i = left; i <= right; i++) {
		a[i] = b[i];
	}

}
void mergeSort(vector<int>& a, vector<int>& b, int left, int right) {

	if (left < right) {
		int mid = (left + right) / 2; //midpoint
		mergeSort(a, b, left, mid);
		mergeSort(a, b, mid + 1, right);
		merge(a, b, left, mid, right);
		copy(b, a, left, right);
	}
}

//binary seaech
int binarySearch(vector<int>& a, int first, int size, int target, bool& found, int& location) {
	if (a.size() == 0) {
		found = true;
		return -1;
	}
	else {
		int middle = first + size / 2;

		if (target == a[middle]) {
			location = middle;
			found = true;
			return middle;
		}
		//check left side
		else if (target < a[middle]) {
			return binarySearch(a, first, size / 2, target, found, location);
		}
		//check right side
		else {
			return binarySearch(a, middle + 1, (size - 1) / 2, target, found, location);
		}
	}
}

int main() {
	vector<int> inputs = { 40,20,10,80,60,50,7,30,100 };
	vector<int> temp(inputs.size()); // temp holder
	bool found = false;
	int location = -1;
	//inputs
	cout << "Inputs: ";
	for (int num : inputs) {
		cout << num << " ";
	}
	//merge sort
	mergeSort(inputs, temp, 0, inputs.size() - 1);
	cout << "\nAfter Merge Sort:\n";
	for (int num : inputs) {
		cout << num << " ";
	}

	//bindary search 
	cout << "\n Binary Search\n";
	int target1;
	//
	cout << "Choose target: ";
	cin >> target1;
	int result = binarySearch(inputs, 0, inputs.size(), target1, found, location);

	if (found) {
		cout << "Target found at index: " << result << endl;

	}
	else {
		cout << "Target Not in list" << endl; ;
	}
	return 0;
}
