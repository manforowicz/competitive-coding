// F

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// freopen("a.in", "r", stdin);
	
	int n, T, k; cin >> n >> T >> k;
	
	// max_value[time][num_boosts] is the maximum value
	// given this configuration
	vector<vector<int>> max_value(T + 1, vector<int>(k + 1, 0));
	
	
	// this loop iterates over all the items.
	for (int i = 0; i < n; i++) {
		int cost, value; cin >> cost >> value;
		
		// iterates over the times
		for (int time = 0; time + cost <= T; time++) {
			
			// iterates num turbo boost
			for (int num_boosts = 0; num_boosts <= k; num_boosts++) {
				int new_value = max_value[time][num_boosts] + value;
				
				max_value[time + cost][num_boosts] = max(max_value[time + cost][num_boosts], new_value);
				
				if (num_boosts + 1 <= k) {
					max_value[time + cost / 2][num_boosts + 1] = max(max_value[time + cost / 2][num_boosts + 1], new_value);
				}
			}
		}
		
	}
	
	for (vector<int> v : max_value) {
		for (int val : v) {
			cout << val << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	
	
	
	// cout << max_value[T - 1][k] - max_value[T][0];
	
}
