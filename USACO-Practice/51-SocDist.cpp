#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("socdist.in", "r", stdin);
	freopen("socdist.out", "w", stdout);
	
	int n, m; cin >> n >> m;
	vector<pair<int64_t, int64_t>> grass(m);
	for (pair<int64_t, int64_t>& interval : grass) {
		cin >> interval.first >> interval.second;
	}
	sort(grass.begin(), grass.end());
	
	int64_t dLower = 1;
	int64_t dUpper = grass.back().second / (n - 1) + 1;
	while (dUpper - dLower > 1) {
		int64_t d = (dLower + dUpper) / 2;
		int64_t cowsPlaced = 1;
		int64_t current = grass[0].first;
		int i = 0;
		while (i < m) {
			
			if (current+d <= grass[i].second) {
				current = max(current+d, grass[i].first);
				cowsPlaced++;
			} else {
				i++;
			}
		}
		if (cowsPlaced < n) dUpper = d;
		else dLower = d;
		
	}
	
	cout << dLower;

	return 0;
}
