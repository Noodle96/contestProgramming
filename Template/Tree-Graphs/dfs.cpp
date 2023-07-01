#include <bits/stdc++.h>
using namespace std;

int n = 6;
vector<vector<int>> adj(n);
vector<bool> visited(n);

void dfs(int current_node) {
	cout << "current node: " << current_node  << endl;
	cout << "visited ?: " << visited[current_node]<<endl;
	if (visited[current_node]){
		return; 
	}
	visited[current_node] = true;
	for (int neighbor : adj[current_node]){
		dfs(neighbor);
	}
}

int main() {
	/*
	 * Define adjacency list and read in problem-specific input
	 *
	 * In this example, we've provided "dummy input" that's
	 * reflected in the GIF above to help illustrate the
	 * order of the recrusive calls.
	 */
	adj[0] = {1, 2, 4};
	adj[1] = {3, 4};
	adj[2] = {5};

	for (int i = 0; i < n; i++) {
		// iterate over all connected components in the graph
		if (!visited[i]) { dfs(i); }
	}
}