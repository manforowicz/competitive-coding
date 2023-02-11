#include <bits/stdc++.h>
using namespace std;


int main() {
	//freopen("in.in", "r", stdin);
	int n, m; cin >> n >> m;
	vector<pair<int, int>> cows(n);
	vector<int> takenCereal(m+1);
	vector<int> disputedBoxes;
	
	for (auto& cow : cows) {
		cin >> cow.first >> cow.second;
		takenCereal[cow.first]++;
		if (takenCereal[cow.first] == 2) {
			disputedBoxes.push_back(cow.first);
		}
	}
	
	//for (int i=0; i<(int)takenCereal.size(); i++) {
	//	cout << i << "(" << takenCereal[i] << ") ";
	//}
	//cout << endl;
	//for (int box : disputedBoxes) {
	//	cout << box << " ";
	//}
	//cout << endl;
	
	sort(disputedBoxes.begin(), disputedBoxes.end());
	vector<int> IdOfDisputed(disputedBoxes.back()+1);
	for (int i=0; i<(int)disputedBoxes.size(); i++) {
		IdOfDisputed[disputedBoxes[i]] = i;
	}
	
	
	vector<vector<int>> fightingCows(disputedBoxes.size());
	for (int i=0; i<n; i++) {
		if (takenCereal[cows[i].first] > 1) {
			fightingCows[IdOfDisputed[cows[i].first]].push_back(i);
		}
	}
	
	vector<int> order(n);
	for (int i=0; i<n; i++) {
		order[i] = i+1;
	}
	int hungry = 0;
	
	for (auto fight : fightingCows) {
		for (int i : fight) {
			if (takenCereal[cows[i].second]) {
				iter_swap(cows.begin() + fight[0], cows.begin() + i);
				iter_swap(order.begin() + fight[0], order.begin() + i);
				break;
			}
		}
		for (int i=1; i<(int)fight.size(); i++) {
			if (takenCereal[cows[fight[i]].second]) hungry++;
			else takenCereal[cows[fight[i]].second]++;
		}
	}
	
	cout << hungry << "\n";
	for (int id : order) {
		cout << id << "\n";
	}

	
	return 0;
}
