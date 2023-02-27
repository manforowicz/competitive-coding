#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	
	vector<pair<int, int>> list;
	
	for (int i = 0; i < n-1; i++) {
		int pos; cin >> pos;
		list.push_back({pos, i+2});
	}
	
	sort(list.begin(), list.end());
	
	cout << "1 ";
	
	for (pair<int, int> val : list) {
		cout << val.second << ' ';
	}
}
