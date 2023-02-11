#include <bits/stdc++.h>
using namespace std;


bool ycmp (const pair<int, int>& a, const pair<int, int>& b) {
	return a.second < b.second;
}

int main() {
	//freopen("in.in", "r", stdin);
	int n; cin >> n;
	vector<pair<int, int>> cows(n);
	
	for (pair<int, int>& cow : cows) {
		cin >> cow.first >> cow.second;
	}
	//Coordinate Compression
	sort(cows.begin(), cows.end());
	for (int i=0; i<n; i++) {
		cows[i].first = i+1;
	}
	sort(cows.begin(), cows.end(), ycmp);
	for (int i=0; i<n; i++) {
		cows[i].second = i+1;
	}
	
	vector<vector<int>> prefix (n+1, vector<int>(n+1));
	
	for (pair<int, int>& cow : cows) {
		prefix[cow.first][cow.second]++;
	}
	
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			prefix[i][j] += prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
		}
	}

	long long sum = 1;
	for (int i=0; i<n; i++) {
		for (int j=i; j<n; j++) {
			int top = cows[i].second;
			int bottom = cows[j].second;
			int left = min(cows[i].first, cows[j].first);
			int right = max(cows[i].first, cows[j].first);
			sum += (prefix[left][bottom] - prefix[left][top-1]) *
				(prefix[n][bottom] - prefix[right-1][bottom] - prefix[n][top-1] + prefix[right-1][top-1]);
		}
	}
	cout << sum;
			
	
	return 0;
}
