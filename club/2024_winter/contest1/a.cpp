#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	
	for (int i = 0; i < t; i++) {
		int n, a, b; cin >> n >> a >> b;
		
		if (a == b && b == n) {
			cout << "Yes\n";
		} else if (a + b < n - 1) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
		
	}
	
}
