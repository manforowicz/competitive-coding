#include <bits/stdc++.h>
using namespace std;

struct Ball {
	int tube, height;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	
	vector<vector<Ball>> colors(n+2); // index is color
	
	vector<int> unfilledTubes(n+1);
	
	for (int i = 0; i <= n; i++) {
		int b, m, t; cin >> b >> m >> t;
		
		colors[b].push_back({
