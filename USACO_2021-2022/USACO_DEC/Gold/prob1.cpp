#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	freopen("in.in", "r", stdin);
	int t, n, k; cin >> t >> n >> k;
	
	vector<int> pos(n);
	vector<int> weight(n);
	
	for (int i=0; i<n; i++) {
		cin >> pos[i] >> weight[i];
	}
	
	if (t==1) {
		int totalWeight = 0;
		int minWeight = weight[0];
		for (int i=1; i<n; i++) {
			if (pos[i] - pos[i-1] > k) {
				totalWeight += minWeight;
				minWeight = INT_MAX;
			}
			minWeight = min(minWeight, weight[i]);
		}
		totalWeight += minWeight;
		cout << totalWeight;
		return 0;
	}
	
}
