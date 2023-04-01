#include <bits/stdc++.h>
using namespace std;



int main() {
	//freopen("in.txt", "r", stdin);
	int t; cin >> t;
	
	for (int test = 0; test < t; test++) {
		
		int64_t minShift = -10e10;
		int64_t maxShift = 10e10;
		
		int64_t n, w, h; cin >> n >> w >> h;
		
		vector<int64_t> cakes(n);
		for (int64_t& cake : cakes) {
			cin >> cake;
		}
		
		vector<int64_t> dispensers(n);
		for (int64_t& d : dispensers) {
			cin >> d;
		}
		
		for (int i = 0; i < n; i++) {
			int64_t rightShift = (dispensers[i] - h) - (cakes[i] - w);
			int64_t leftShift = (dispensers[i] + h) - (cakes[i] + w);
			
			minShift = max(minShift, leftShift);
			maxShift = min(maxShift, rightShift);
		}
		
		if (maxShift >= minShift) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
