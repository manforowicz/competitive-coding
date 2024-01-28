#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	
	// map of the world
	vector<string> world(n);
	
	// stores the number of "o" in each row
	vector<int> row_sums(n, 0);
	
	// stores the number of "o" in each column
	vector<int> column_sums(n, 0);
	
	// fill in these vectors
	for (int y = 0; y < n; y++) {
		string s; cin >> world[y];
		for (int x = 0; x < n; x++) {
			if (world[y][x] == 'o') {
				row_sums[y] += 1;
				column_sums[x] += 1;
			}
		}
	}
	
	int64_t answer = 0;
	
	// iterate over all the "o" cells
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (world[y][x] == 'o') {
				answer += (row_sums[y] - 1) * (column_sums[x] - 1);
			}
		}
	}
	cout << answer << '\n';
}
