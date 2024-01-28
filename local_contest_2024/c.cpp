// C

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("c.in", "r", stdin);
	
	// n = 4, m = 5
	int n, m; cin >> n >> m;
	
	vector<string> world;
	
	for (int y = 0; y < n; y++) {
		string s; cin >> s;
		s.append("F");
		world.push_back(s);
	}
	
	// padding
	world.push_back(string(m + 1, 'F'));
	
	// cout << "WORLD" << endl;
	
	// for (string s : world) {
	// 	cout << s << '\n';
	// }
	
	
	// cout << "DEBUG" << endl;
	
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			
			// cout << "Y: " << y << " X: " << x << endl;
			
			int empty = 0;
			
			if (world[y][x] == '.') {
				empty += 1;
			}
			if (world[y+1][x] == '.') {
				empty += 1;
			}
			if (world[y][x+1] == '.') {
				empty += 1;
			}
			if (world[y+1][x+1] == '.') {
				empty += 1;
			}
			
			// cout << empty << '\n';
			
			if (empty >= 3) {
				cout << "YARGHHH" << '\n';
				return 0;
			}
		}
	}
		
	
	cout << "FFFGHHH" << '\n';
}
