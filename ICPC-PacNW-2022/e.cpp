#include <bits/stdc++.h>
using namespace std;

struct Pos {
	int tube, height;
};

struct Color {
	int color, i;
};

// need to know where balls of color are
// need to know what balls are at position

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	
	vector<vector<Pos>> colors(n+1); // [color][i]
	
	vector<vector<Color>> positions(n+2, vector<int>(3)); // [tube][height]
	
	
	for (int i = 0; i <= n; i++) {
		int b, m, t; cin >> b >> m >> t;
		
		positions[i][0] = {b, 0};
		
		colors[b].push_back({i, 0}):;
		colors[m].push_back({i, 1});
		colors[t].push_back({i, 2});
	}
}
