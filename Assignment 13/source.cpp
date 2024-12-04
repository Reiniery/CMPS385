#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


vector<int> largetsSubsetAlg(vector<int> inputs) {

	unordered_set<int> hashMap;
	vector<int> subset;


	//insert into Hash =table
	hashMap.insert(inputs.begin(), inputs.end());
	
	for (int x : inputs) {
		//find a sequence
		if (hashMap.find(x - 1) == hashMap.end()) {
			vector<int> currSubset;
			int currentNum = x;
			//find how long sequence is
			while (hashMap.find(currentNum) != hashMap.end()) {
				currSubset.push_back(currentNum);
				currentNum++;
			}
			//compare to largest seq yet
			if (currSubset.size() > subset.size()) {
				subset = currSubset;
			}

		}


	}

	return subset;
}




int main() {

	vector<int> inputs = { 1,3,8,14,4,10,2,11 };

	vector<int> answer = largetsSubsetAlg(inputs);

	cout << "Largest Subset:" << endl;
	for (int x : answer) {
		cout << x << " ";
	}
	return 0;
}
