#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	int64_t t; cin >> t;
	
	for (int i = 0; i < t; i++) {
		int64_t a, b; cin >> a >> b;
		int64_t sum = a + b;
		int64_t biggest = max(a, b);
		int64_t smallest = min(a, b);
		
		if (sum % 3 == 0 && biggest <= smallest*2) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
