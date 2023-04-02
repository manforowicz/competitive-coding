#include <bits/stdc++.h>
using namespace std;

int get_dead(vector<vector<int>>& links, int root, int parent) {
	int totalDead = 1;
	int maxDead = 0;
	for (int neighbor : links[root]) {
		if (neighbor != parent) {
			int childDead = get_dead(links, neighbor, root);
			maxDead = max(maxDead, childDead-1);
			totalDead += childDead;
		}
	}
	return totalDead - maxDead;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("in.txt", "r", stdin);
	
	int tests; cin >> tests;
	for (int t = 0; t < tests; t++) {
		int n; cin >> n;
		vector<vector<int>> links(n);
		for (int i = 0; i < n - 1; i++) {
			int u, v; cin >> u >> v; u -= 1; v -= 1;
			links[u].push_back(v);
			links[v].push_back(u);
		}
		cout << n - get_dead(links, 0, -1) << '\n';;
	}
}
		
