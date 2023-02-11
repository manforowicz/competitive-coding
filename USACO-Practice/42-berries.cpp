#include <bits/stdc++.h>
using namespace std;

int main() {
	sync_with_stdio(0);
	freopen("berries.in", "r", stdin);
	
	int n, k; cin >> n >> k;
	vector<int> berries(n);
	for (int &bush : berries) {
		cin >> bush;
	}
	sort(berries.begin(), berries.end(), greater<int>);
	berries.resize(k);
	
	vector<int> baskets
	
	
	return 0;
}
