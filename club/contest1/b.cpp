#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("in.txt", "r", stdin);

	int cases; cin >> cases;
	for (int t = 0; t < cases; t++) {
		
		int64_t l, r, a; cin >> l >> r >> a;
		int64_t x = (r+1) / a * a - 1;
		if (x < l) x = r;
		cout << x / a + x % a << '\n';
	}
}
