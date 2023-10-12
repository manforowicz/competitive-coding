#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//freopen("in.txt", "r", stdin);
	
	int tests; cin >> tests;
	
	for (int t = 0; t < tests; t++) {
		int n, k; cin >> n >> k;
		
		if (2*k-1 > n) {
			cout << "-1\n";
		} else {
			for (int x = 1; x <= n; x++) {
				for (int y = 1; y <= n; y++) {
					if (k > 0 && x % 2 == 1 && x == y) {
						cout << 'R';
						k -= 1;
					} else {
						cout << '.';
					}
				}
				cout << '\n';
			}
		}
	}
}
