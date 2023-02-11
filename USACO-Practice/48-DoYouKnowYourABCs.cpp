#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	freopen("in.in", "r", stdin);
	
	int t; cin >> t;
	
	for (int i=0; i<t; i++) {
		int n; cin >> n;
		vector<int> nums(n);
		for (int& num : nums) {
			cin >> num;
		}
		
