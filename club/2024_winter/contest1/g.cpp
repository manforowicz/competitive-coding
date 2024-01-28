#include <bits/stdc++.h>
using namespace std;

bool solve() {
	int64_t n, a, b; cin >> n >> a >> b;
	int64_t product = 1;
	
	do {
		if ((n - product) % b == 0) {
			return true;
		}
		product *= a;
	} while (product <= n && a != 1);
	
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	
	for (int test = 0; test < t; test++) {
		if (solve()) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}		
	}
}
