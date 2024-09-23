#include <bits/stdc++.h>
using namespace std;

// TODO: NOT FINISHED

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	
	for (int test = 0; test < t; test++) {
		int n; cin >> n;
		vector<int> arr(n);
		
		for (int& elem : arr) {
			cin >> elem;
		}
		
		sort(arr.begin(), arr.end());
		
		cout << num << '\n';
	}
}
