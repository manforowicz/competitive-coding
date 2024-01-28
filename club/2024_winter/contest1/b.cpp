#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	
	for (int test = 0; test < t; test++) {
		int n, k; cin >> n >> k;
		
		int sum = (1 + (n - 1) / k) * k;
		int ans = 1 + (sum - 1) / n;
		cout << ans << '\n';
		
	} 
	
}
