#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

struct {

};

void bfs(const unordered_map<char,vector<char>>& graph, char start) {
	
	queue<char> q;
	unordered_map<char,bool> visited;
	//inseet into queue
	q.push(start);
	visited[start] = true;
	
	while (!q.empty()) {
		//get first from queue
		char node = q.front();
		cout << node << " ";
		q.pop();
		//visit unvisited nodes
		for (char neighbor : graph.at(node)) {
			if (!visited[neighbor]) {
			visited[neighbor] = true;
			q.push(neighbor);
			}
			
		}
	}
}
void dfs(const unordered_map<char, vector<char>>& graph, char start) {

	stack<char> q;
	unordered_map<char, bool> visited;
	//push first into stack
	q.push(start);
	while (!q.empty()) {
		//get top
		char node = q.top();
		q.pop();
		//go down a level farthest left
		if (!visited[node]) {
			visited[node] = true;
			cout << node << " "; 
		}
		//visit neighbors after bottom has been reached
		for(auto it =graph.at(node).rbegin();it!=graph.at(node).rend();++it){
			if (!visited[*it]) {
				q.push(*it);
			}

		

		

		}
	}
}

int main() {
	
	unordered_map<char, vector<char>> graph = {
		{'v', {'u', 'w', 'x'}},
		{'u', {'v', 'q', 't'}},
		{'w', {'v'}},
		{'x', {'v'}},
		{'q', {'u', 'r', 's'}},
		{'r', {'q'}},
		{'s', {'q'}},
		{'t', {'u'}}
	};

	cout << "BFS Traversal" << endl;

	bfs(graph, graph.begin()->first);
	 
	cout << "\nDFS Traversal" << endl;
	dfs(graph, graph.begin()->first);


	return 0;
}
