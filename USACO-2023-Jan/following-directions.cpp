#include <bits/stdc++.h>
using namespace std;

int64_t cost(vector<int> rightCosts, vector<int> downCosts, vector<vector<int>> volume) {
	int64_t sum = 0;
	for (size_t i = 0; i < rightCosts.size(); i++) {
		sum += rightCosts[i] * volume[i].back();
	}
	for (size_t i = 0; i < downCosts.size(); i++) {
		sum += downCosts[i] * volume.back()[i];
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	
	vector<string> world(n);
	
	vector<int> rightCosts(n);
	vector<int> downCosts(n);
	vector<vector<int>> volume(n+1, vector<int>(n+1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			volume[i][j] = 1;
		}
	}
	
	for (int i = 0; i < n; i++) {
		cin >> world[i];
		cin >> rightCosts[i];
		for (int j = 0; j < n; j++) {
			if (world[i][j] == 'R') {
				volume[i][j+1] += volume[i][j];
			} else {
				volume[i+1][j] += volume[i][j];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> downCosts[i];
	}
	
	int64_t prev_cost = cost(rightCosts, downCosts, volume);
	cout << prev_cost << '\n';
	
	int q; cin >> q;
	
	for (int i = 0; i < q; i++) {
		int flip_x, flip_y; cin >> flip_y >> flip_x;
		flip_x--; flip_y--;
		int number = volume[flip_y][flip_x];
		int x = flip_x;
		int y = flip_y;
		
		
		while (y < n && x < n) {
			if (world[y][x] == 'R') {
				x += 1;
			} else {
				y += 1;
			}
			volume[y][x] -= number;
		}
		if (y == n) {
			prev_cost -= number * downCosts[x];
		} else {
			prev_cost -= number * rightCosts[y];
		}
		
		if (world[flip_y][flip_x] == 'R') {
			world[flip_y][flip_x] = 'D';
		} else {
			world[flip_y][flip_x] = 'R';
		}
		
		x = flip_x;
		y = flip_y;
		while (y < n && x < n) {
			if (world[y][x] == 'R') {
				x += 1;
			} else {
				y += 1;
			}
			volume[y][x] += number;
		}
		if (y == n) {
			prev_cost += number * downCosts[x];
		} else {
			prev_cost += number * rightCosts[y];
		}
		
		cout << prev_cost << '\n';
	}	
}
		
