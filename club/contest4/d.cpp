#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("planting.in", "r", stdin);
	freopen("planting.out", "w", stdout);
	
	int n; cin >> n;
	vector<int> degree(n);
	
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		degree[a-1] += 1;
		degree[b-1] += 1;
	}
	cout << *max_element(degree.begin(), degree.end()) + 1;
}
