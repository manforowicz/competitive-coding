#include <bits/stdc++.h>
using namespace std;

struct Cow {
	int first, second, ID;
	bool operator < (const Cow& b) { return first < b.first;};
};

int main() {
	//freopen("in.in", "r", stdin);
	int n, m; cin >> n >> m;
	vector<Cow> cows(n);
	vector<int> takenCereal(m+1);
	
	for (int i=0; i<n; i++) {
		cin >> cows[i].first >> cows[i].second;
		cows[i].ID = i+1;
		takenCereal[cows[i].first]++;
	}
	sort(cows.begin(), cows.end());
	

	
	int currTaste = cows[0].first;
	int currI = 0;
	for (int i=0; i<n; i++) {
		if (cows[i].first != currTaste) {
			currTaste = cows[i].first;
			currI = i;
		}
		
		if (i - currI >= 1) {
			if (takenCereal[cows[i].second]) {
				iter_swap(cows.begin() + currI, cows.begin() + i);
			}
			takenCereal[cows[i].second]++;
		}
	}
	
	int hungry = 0;
	
	fill(takenCereal.begin(), takenCereal.end(), 0);
	
	for (auto& cow : cows) {
		if (!takenCereal[cow.first]) {
			takenCereal[cow.first]++;
		}
		else if (takenCereal[cow.first] and !takenCereal[cow.second]) {
			takenCereal[cow.second]++;
		}
		else if (takenCereal[cow.first] and takenCereal[cow.second]) {
			hungry++;
		}
	

	}
	
	cout << hungry << "\n";
	for (Cow cow : cows) {
		cout << cow.ID << "\n";
	}
	
	return 0;
}
