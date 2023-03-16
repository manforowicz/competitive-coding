// H: Branching Manager
// http://acmicpc-pacnw.org/ProblemSet/Spring2023/pacnw_div1.pdf
// SOLVED (According to sample cases)

#include <bits/stdc++.h>
using namespace std;

vector<set<int>> graph;
vector<int> destinations;
size_t destI = 0;

void traverse(int city, unordered_set<int>& available) {
	available.insert(city);
	
	while (destI < destinations.size() &&
			available.find(destinations[destI]) != available.end()) {
		destI++;
	}
	for (int next : graph[city]) {
		traverse(next, available);
	}
	available.erase(city);
}


int main() {
	// Magic C++ stuff that makes input/output faster
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m; cin >> n >> m;
	
	// Setting graph to have n+1 elements
	graph.resize(n+1);
	
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		graph[a].insert(b);
	}
	
	for (int i = 0; i < m; i++) {
		int destination; cin >> destination;
		destinations.push_back(destination);
	}
	
	unordered_set<int> available;
	traverse(1, available);
	
	cout << destI;
}

