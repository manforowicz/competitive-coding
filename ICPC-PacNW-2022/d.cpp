#include <bits/stdc++.h>
using namespace std;

// NOT SOLVED. WRONG ALGORITHM.

int barn_x;

struct Treasure {
	int x, y, value, id;
	
	bool operator < (const Treasure &b) const {
		return (double) (x - barn_x)/y < (double) (b.x - barn_x)/b.y;
	}
};


vector<int64_t> makePrefix(vector<Treasure> &treasures) {
	sort(treasures.begin(), treasures.end());
	int64_t sum = 0;
	vector<int64_t> prefix(treasures.size());
	
	for (Treasure t : treasures) {
		prefix[t.id] = sum;
		sum += t.value;
	}
	return prefix;
}
		


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("in.txt", "r", stdin);
	
	int n; cin >> n >> barn_x;
	
	vector<Treasure> treasures(n);
	
	for (int i = 0; i < n; i++) {
		int x, y, value; cin >> x >> y >> value;
		treasures[i] = {x, y, value, i};
	}
	
	vector<int64_t> rightPrefix = makePrefix(treasures);
	barn_x = 0;
	vector<int64_t> leftPrefix = makePrefix(treasures);
	
	
	for (int i = 0; i < n; i++) {
		cout << leftPrefix[i] << ' ' << rightPrefix[i] << '\n';
	}
}
