#include <bits/stdc++.h>
using namespace std;



int main() {
	freopen("in.in", "r", stdin);
	int n; cin >> n;
	
	vector<int> cows(n);
	for (int& cow : cows) {
		cin >> cow;
	}
	
	
	vector<int> rightBounds;
	set<int> currCows;
	
	for (int i=0; i<n; i++) {
		currCows.insert(cows[i]);
		auto remove = currCows.lower_bound(cows[i]);
		auto it = remove;
		while (it != currCows.begin()) {
			it--;
			rightBounds.push_back(i);
		}
		currCows.erase(currCows.begin(), remove);
	}
	sort(rightBounds.begin(), rightBounds.end());
	
	for (int bound : rightBounds) {
		cout << bound << " ";
	}
	
	vector<int> leftBounds;
	currCows.clear();
	
	for (int i=n-1; i>=0; i--) {
		currCows.insert(cows[i]);
		auto remove = currCows.lower_bound(cows[i]);
		auto it = remove;
		while (it != currCows.begin()) {
			it--;
			leftBounds.push_back(i);
		}
		currCows.erase(currCows.begin(), remove);
	}
	sort(leftBounds.begin(), leftBounds.end());
	
	cout << "\n\n\n\n";
	for (int bound : leftBounds) {
		cout << bound << " ";
	}
	
	
	
	
	return 0;
}
