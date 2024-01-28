#include <bits/stdc++.h>
using namespace std;

int64_t count_nodes(int prev, int curr, int64_t &ans, const vector<vector<int>> &adj) {
	
	int64_t sum = 0;
	
	vector<int64_t> child_counts;
	
	for (int neighbor : adj[curr]) {
		if (neighbor == prev) {
			continue;
		}
		child_counts.push_back(count_nodes(curr, neighbor, ans, adj));
		sum += child_counts.back();
	}
	
	
	for (int64_t count : child_counts) {
		ans += (sum - count) * count;
	}
	cout << sum + 1 << endl;
		
	return sum + 1;
}

int64_t choose(int64_t n, int64_t k) {
    if (k == 0) {
		return 1;
	 }
    return (n * choose(n - 1, k - 1)) / k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int64_t n; cin >> n;
	
	vector<vector<int>> adj(n + 1);
	
	for (int64_t i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	int64_t ans = 0;
	
	count_nodes(-1, 1, ans, adj);
	
	cout << choose(n, 3) - ans << '\n';
}
	 
	
