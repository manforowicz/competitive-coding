#include <bits/stdc++.h>
using namespace std;

int cowsAdded = 0;
vector<vector<bool>> world(3000, vector<bool>(3000));

void insertCow(int x, int y);

void recursive(int x, int y) {
	
	if (!world[x][y]) {
		return;
	}
	
	pair<int, int> emptyNeighbor;
	int emptyNeighbors = 0;
	
	pair<int, int> neighbors[4] = {{x,y+1}, {x,y-1}, {x-1,y}, {x+1,y}};
	for (const auto& neighbor : neighbors) {
		if (!world[neighbor.first][neighbor.second]) {
			emptyNeighbors++;
			emptyNeighbor = neighbor;
		}
	}

	if (emptyNeighbors == 1) {
		cowsAdded++;
		insertCow(emptyNeighbor.first, emptyNeighbor.second);
	}
}

void insertCow(int x, int y) {
	world[x][y] = true;
	recursive(x, y);
	recursive(x, y+1);
	recursive(x, y-1);
	recursive(x+1, y);
	recursive(x-1, y);
}

int main() {
	ios::sync_with_stdio(0);
	//freopen("in.in", "r", stdin);
	int n; cin >> n;
	
	for (int i=0; i<n; i++) {
		int x, y; cin >> x >> y;
		x += 1000;
		y += 1000;
		if (world[x][y]) {
			cowsAdded--;
		} else {
			insertCow(x, y);
		}
		cout << cowsAdded << "\n";	
	}
	return 0;
}
