#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	//freopen("in.in", "r", stdin);
	int n, k; cin >> n >> k;
	
	set<int> occupied;
	
	for (int i=0; i<n; i++) {
		int ancestor; cin >> ancestor;
		occupied.insert(ancestor/12);
	}
	
	multiset<int, greater<int>> emptyLengths;
	
	
	int prev = -1;
	for (int full : occupied) {
		emptyLengths.insert(full-prev-1);
		//cout << full - prev - 1 << endl;
		prev = full;
	}
	//cout << endl << endl;
	
	int years = *occupied.rbegin() + 1;
	auto it = emptyLengths.begin();
	int jumps = 1;
	while (it != emptyLengths.end() and jumps < k) {
		years -= *it;
		it++;
		jumps++;
	}
	cout << years * 12;
		
		
	
	return 0;
}
