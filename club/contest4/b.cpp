#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int64_t n, k; cin >> n >> k;
	int64_t cost = k + 1;
	int64_t prev; cin >> prev;
	
	for (int64_t i = 0; i < n - 1; i++) {
		int64_t curr; cin >> curr;
		cost += min(curr - prev, k+1);
		prev = curr;
	}
	cout << cost;
}
