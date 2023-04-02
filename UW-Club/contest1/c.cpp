#include <bits/stdc++.h>
using namespace std;

int64_t get_length() {
	int k; cin >> k;
	int64_t min; cin >> min;
	for (int i = 1; i < k-1; i++) {
		int ignore; cin >> ignore;
	}
	int64_t max; cin >> max;
	return max - min;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("in.txt", "r", stdin);
	
	int tests; cin >> tests;
	
	for (int t = 0; t < tests; t++) {
		int64_t w, h; cin >> w >> h;
		int64_t bottom = h * get_length();
		int64_t top = h * get_length();
		int64_t left = w * get_length();
		int64_t right = w * get_length();
		
		cout << max(max(bottom, top), max(left, right)) << '\n';
	}
}
