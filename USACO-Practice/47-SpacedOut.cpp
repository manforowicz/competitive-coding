#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	//freopen("in.in", "r", stdin);
	int n; cin >> n;
	vector<vector<int>> world(n, vector<int>(n));
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> world[i][j];	
		}
	}
	
	int maxValA = 0;
	for (int i=0; i<n; i++) {
		int rowValA = 0;
		for (int j=0; j<n; j+=2) {
			rowValA += world[i][j];
		}
		int rowValB = 0;
		for (int j=1; j<n; j+=2) {
			rowValB += world[i][j];
		}
		maxValA += max(rowValA, rowValB);
	}
	
	int maxValB = 0;
	for (int i=0; i<n; i++) {
		int rowValA = 0;
		for (int j=0; j<n; j+=2) {
			rowValA += world[j][i];
		}
		int rowValB = 0;
		for (int j=1; j<n; j+=2) {
			rowValB += world[j][i];
		}
		maxValB += max(rowValA, rowValB);
	}
			
	cout << max(maxValA, maxValB);	
	
	return 0;
}
