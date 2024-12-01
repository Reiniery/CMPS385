#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>

using namespace std;

//build edges
struct Edge {
	int src, dest, weight;
};


int prim(int n, vector<vector<Edge>> List) {
	//lambda function to create to make pq into min-heap
	auto compare = [](const Edge& a, const Edge& b) {
		return a.weight > b.weight;
	};

	vector<bool> visited(n, false); //keep trach of visited edges

	int mstWeight = 0;

	priority_queue<Edge, vector<Edge>, decltype(compare)>q(compare);//decltype(compare): use lambda function//q(compare):set the order of by weight

	visited[0] = true;//starting vertex

	//insert all edges in the list to priorty queue
	for (const auto& edge : List[0]) {
		q.push(edge);
	}
	cout << "Start"<<setw(5) << "Dest"<< setw(7) << "Weight"<<endl;
	
	while (!q.empty()) {
		Edge currentEdge = q.top(); //get current 
		q.pop(); //remove from pq
		int v = currentEdge.dest;

		if (!visited[v]) {
			visited[v] = true;
			mstWeight += currentEdge.weight;
			//display weights
			cout << currentEdge.src +1 << setw(7) << currentEdge.dest +1 << setw(7) << currentEdge.weight << endl;
		}
		//add edges from new visit
		for (const auto& edge : List[v]) {
			if (!visited[edge.dest]) {
				q.push(edge);
			}
		}
	}
	return mstWeight;



}



int main() {
	vector<vector<Edge>> list = {
		// {src(index), dest, weight}
		{{0, 1, 4}, {0, 3, 1}, {0, 4, 8}},       // Node 0
		{{1, 0, 4}, {1, 2, 2}, {1, 3, 2}, {1, 4, 6}, {1, 5, 1}}, // Node 1
		{{2, 1, 2}, {2, 3, 2}, {2, 4, 6}},       // Node 2
		{{3, 0, 1}, {3, 1, 2}, {3, 4, 11}, {3, 6, 9}, {3, 7, 8}}, // Node 3
		{{4, 0, 8}, {4, 1, 6}, {4, 2, 6}, {4, 3, 11}, {4, 5, 3}, {4, 6, 4}, {4, 7, 1}, {4, 8, 5}}, // Node 4
		{{5, 1, 1}, {5, 2, 5}, {5, 4, 3}, {5, 7, 7}, {5, 8, 8}}, // Node 5
		{{6, 3, 9}, {6, 4, 4}, {6, 7, 6}},       // Node 6
		{{7, 3, 8}, {7, 4, 1}, {7, 5, 7}, {7, 6, 6}, {7, 8, 3}}, // Node 7
		{{8, 4, 5}, {8, 5, 8}, {8, 7, 3}}        // Node 8
	};

	cout <<"Total Weight: " << prim(list.size(), list);

	return 0;
}
