#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	
	for (int test = 0; test < t; test++) {
		int n; cin >> n;
		vector<int64_t> arr(n);
		
		for (int64_t& num : arr) {
			cin >> num;
		}
		
		int64_t mini = *min_element(arr.begin(), arr.end());
		int64_t maxi = *max_element(arr.begin(), arr.end());
		cout << maxi - mini << '\n';
	}
}
