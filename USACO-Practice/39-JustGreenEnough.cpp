#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	freopen("in.in", "r", stdin);
	int n; cin >> n;
	
	vector<pair<int, int>> anchors;
	vector<vector<int>> world(n, vector<int>(n));
	
	for (int x=0; x<n; x++) {
		for (int y=0; y<n; y++) {
			int in; cin >> in;
			
			if (in == 100) {
				world[x][y] = 0;
				anchors.push_back({x, y});
			} else if (in < 100) {
				world[x][y] = -1;
			} else {
				world[x][y] = 1;
			}
		}
	}
	
	
	int count = 0;
	
	for (pair<int, int> anchor : anchors) {
		
	}
	
	
	return 0;
}
