#include <bits/stdc++.h>
using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, q; cin >> n >> q;
	
	int smallest_uncalled = 1;
	set<int> called;
	
	for (int i = 0; i < q; i++) {
		int type; cin >> type;
		if (type == 1) {
			called.insert(smallest_uncalled);
			smallest_uncalled += 1;
		} else if (type == 2) {
			int x; cin >> x;
			called.erase(x);
		} else {
			cout << *called.begin() << '\n';
		}
	}
}
