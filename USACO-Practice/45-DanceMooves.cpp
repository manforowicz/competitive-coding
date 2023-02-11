#include <bits/stdc++.h>
using namespace std;

struct Cycle {
	unordered_set<int> nodes;
	unordered_set<int> visited;
};

struct Node {
	int origin;
	bool discovered;
	unordered_set<int> visited;
	int totalNumVisited;
};

vector<Node> nodes;
vector<Cycle> cycles;

void search(int i) {
	Node& node = nodes[i];
	if (node.discovered) return;
	node.discovered = true;
	cycles.back().visited.insert(node.visited.begin(), node.visited.end());
	cycles.back().nodes.insert(i);
	search(node.origin);
}
	

int main() {
	ios::sync_with_stdio(0);
	
	//freopen("in.in", "r", stdin);
	
	int n, k; cin >> n >> k;
	nodes.resize(n+1);
	
	for (int i=1; i<=n; i++) {
		nodes[i].origin = i;
		nodes[i].visited.insert(i);
	}
	
	for (int i=0; i<k; i++) {
		int a, b; cin >> a >> b;

		std::swap(nodes[a], nodes[b]);
		
		nodes[a].visited.insert(a);
		nodes[b].visited.insert(b);
	}
	
	for (int i=1; i<=n; i++) {
		if (!nodes[i].discovered) {
			cycles.push_back({});
			search(i);
			for (int node : cycles.back().nodes) {
				nodes[node].totalNumVisited = cycles.back().visited.size();
			}
		}
		cout << nodes[i].totalNumVisited << endl;
	}
	
	return 0;
}
