#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<vector<int>>& graph, int start) {
	int n = graph.size();
	vector<bool> visited(n, false);
	queue<int> q;

	visited[start] = true;
	q.push(start);

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node << " ";

		for (int neighbor : graph[node]) {
			if (!visited[neighbor]) {
				visited[neighbor] = true;
				q.push(neighbor);
			}
		}
	}
}

int main() {
	// Example usage
	vector<vector<int>> graph = {
		{1, 2},
		{0, 2, 3},
		{0, 1, 3},
		{1, 2}
	};

	int startNode = 0;
	bfs(graph, startNode);

	return 0;
}
