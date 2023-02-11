#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	freopen("in.in", "r", stdin);
	int t, n, k; cin >> t >> n >> k;
	
	vector<int> pos(n+1), weight(n+1);
	
	for (int i=0; i<n; i++) {
		cin >> pos[i] >> weight[i];
	}
	
	
	if (t == 1) {
		
		int leftBound = -1;
		int minCow = INT_MAX;
		int totalWeight = 0;
		for (int i=0; i<n; i++) {
			if (not((i - leftBound) % 2 == 0 and pos[i+1] - pos[i-1] > k)) {
				minCow = min(minCow, weight[i]);
			}
			if (i == n-1 or pos[i+1] - pos[i] > k) {
				if ((i - leftBound) % 2 == 1) {
					totalWeight += minCow;
				}
				minCow = INT_MAX;
				leftBound = i;
			}
				
		}
		cout << totalWeight;
	} else {
		
		
		
	}
	
	return 0;
}
