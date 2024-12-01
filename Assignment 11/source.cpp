#include <iostream>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <climits>
using namespace std;

struct Edge {
	int dest;
	int weight;
	Edge(int d, int w) :dest(d), weight(w) {}
};
struct vertex {
	int id;
	int distance;
	vertex(int i, int d) : id(i), distance(d) {}
};

//maintains min heap
struct compareDist {
	bool operator()(const vertex& a, const vertex& b) {
		return a.distance > b.distance;
	}
};

void dijkstra(const unordered_map<int, vector<Edge>>& graph, int start) {
	priority_queue<vertex, vector<vertex>, compareDist> pq;

	unordered_map<int, int> distances;
	unordered_map<int, int> prev;
	unordered_set<int> nodes; //keep track of all nodes

	
	for (auto& pair : graph) {
		int node = pair.first;
		nodes.insert(node);
		for (const auto& edge : pair.second) {
			nodes.insert(edge.dest);
		}

	}
	//initialize all to infinity
	for (int node : nodes) {
		distances[node] = INT_MAX;
		prev[node] = -1;
	}

	distances[start] = 0;

	pq.push(vertex(start, 0));

	//go through queue
	while (!pq.empty()) {
		vertex currVertex = pq.top();
		pq.pop();
		int current = currVertex.id;
		int currDist = currVertex.distance;

		if (currDist > distances[current]) {
			continue;
		}
		//look for v in graph
		if (graph.find(current) != graph.end()) {
			for (const Edge& edge : graph.at(current)) {
				int neighbor = edge.dest;
				int weight = edge.weight;
				int newDist = currDist + weight;

				if (newDist < distances[neighbor]) {
					distances[neighbor] = newDist;
					prev[neighbor] = current;
					pq.push(vertex(neighbor, newDist));

				}
			}
		}
	}
	// Print shortest distances from start
	cout << "Shortest distances from vertex " << start << ":" << endl;
	for (auto& pair : distances) {
		cout << "Vertex " << pair.first << " : ";
		if (pair.second == INT_MAX) {
			cout << "Unreachable" << endl;
		}
		else {
			cout << pair.second << endl;
		}
	}

}


int main() {
	// Define the graph using an adjacency list
	unordered_map<int, vector<Edge>> graph;

	// Add edges to the graph (directed edges)
	
	//v 0
	graph[0].emplace_back(1, 2);
	graph[0].emplace_back(3, 1);
	//1
	graph[1].emplace_back(3, 3);
	graph[1].emplace_back(4, 10);
	//2
	graph[2].emplace_back(0, 4);
	graph[2].emplace_back(5, 5);
	//3
	graph[3].emplace_back(4, 2);
	graph[3].emplace_back(2, 2);
	graph[3].emplace_back(5, 8);
	graph[3].emplace_back(6, 4);
	//4
	graph[4].emplace_back(6, 6);
	//5 did not have any going out
	//6 
	graph[6].emplace_back(5, 1);

	// Run dijkstra's alg starting from v 0
	dijkstra(graph, 0);






	return 0;
}
