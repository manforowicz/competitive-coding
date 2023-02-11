#include <bits/stdc++.h>
using namespace std;

struct Pos {
	int x, y;
	bool operator< (const Pos& other) const {
		//return std::tie(x, y) < std::tie(other.x, other.y);
		if (x == other.x) {
			return (y < other.y);
		} else {
			return (x < other.x);
		}
	}
	bool operator== (const Pos& other) const {
		return std::tie(x, y) == std::tie(other.x, other.y);
	}
};

vector<multiset<Pos>> positions1;
vector<multiset<Pos>> positions2;

void findPositions(vector<multiset<Pos>>& positions) {
	for (int i=1; i < (int)positions.size(); i++) {
		Pos move; cin >> move.x >> move.y;
		for (int j = i; j > 0; j--) {
			for (Pos pos : positions[j-1]) {
				positions[j].insert({pos.x + move.x, pos.y + move.y});
			}
		}
	}
}

int main() {
	freopen("in.in", "r", stdin);
	int n; cin >> n;
	positions1.resize(n/2 + 1);
	positions2.resize((n+1)/2 + 1);
	
	positions1[0].insert({0, 0});
	Pos goal; cin >> goal.x >> goal.y;
	positions2[0].insert(goal);
	
	findPositions(positions1);
	findPositions(positions2);
	
	vector<int> answers(n+1);
	
	for (int i=0; i < (int)positions1.size(); i++) {
		for (Pos pos : positions1[i]) {
			for (int j=0; j < (int)positions2.size(); j++) {
				answers[i+j] += positions2[j].count(pos);
			}
		}
	}
	//--
	for (int i=0; i < (int)positions1.size(); i++) {
		cout << "---" << endl;
		for (Pos pos : positions1[i]) {
			cout << pos.x << " " << pos.y << endl;
		}
	}
	//--
	cout << endl << endl;
	int g; cin >> g;
	cout << g << endl << endl;
	for (int answer : answers) {
		cout << answer << endl;
	}
	
	return 0;
}
