#include <bits/stdc++.h>
using namespace std;

vector<string> world;

struct Photon {
	int x, y, xDir, yDir;
	char pos;
	void move() {
		world[x][y] = pos;
		x += xDir;
		y += yDir;
		pos = world[x][y];
		world[x][y] = 'P';
	}
	char getPos() {
		return pos;
	}
};


vector<Photon> photons;
int64_t bellCount = 0;
int64_t doveCount = 0;



int main() {
	int lines, width; cin >> lines >> width;
	
	
	for (int i = 0; i < lines; i++) {
		string line; cin >> line;
		world.push_back(line);
		size_t found = line.find('C');
		if (found != string::npos) {
			int xDir = 0;
			int yDir = 0;
			if (found == 0) {
				xDir = 1;
			} else if (found == line.size()-1) {
				xDir -= 1;
			} else if (i == 0) {
				yDir = 1;
			} else if (i == lines - 1) {
				yDir = -1;
			}
			photons.push_back({(int) found, i, xDir, yDir, 'C'});
		}
	}
	while (!photons.empty()) {
		for (int i = 0; i < (int) photons.size(); i++) {
			photons[i].move();
		}
	}
}
