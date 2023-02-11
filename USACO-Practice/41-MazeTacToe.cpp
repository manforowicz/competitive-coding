#include <bits/stdc++.h>
using namespace std;

vector<string> world;
vector<int> currentConnected;

string cell(int x, int y) {
	return world[y].substr(x*3, x*3 + 3);
}

void setCell(int x, int y, string s) {
	for (int i = 0; i < 3; i++) {
		world[y][x*3 + i] = s[i];
	}
}

int moveToID(string s) {
	int ID = 0;
	ID += (s[0]-1);
	ID += (s[1]-1) * 3;
	if (s[2] == 'M') {
		ID += 9;
	}
	return ID;
}


void floodFill(int x, int y) {
	string box = cell(x,y);
	if (box == "###") {
		return;
	} else if (box != "..." ) {
		currentConnected.push_back(moveToID(box));
		return;
	}
	setCell(x, y, "###");
	floodFill(x+1, y);
	floodFill(x-1, y);
	floodFill(x, y+1);
	floodFill(x, y-1);
}






int main() {
	ios::sync_with_stdio(0);
	freopen("in.in", "r", stdin);
	
	int n; cin >> n;
	world.resize(n);
	for (string row : world) {
		cin >> row;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			currentConnected.clear();
			floodFill(i, j);
		}
	}
	return 0;
}
	
	
	
