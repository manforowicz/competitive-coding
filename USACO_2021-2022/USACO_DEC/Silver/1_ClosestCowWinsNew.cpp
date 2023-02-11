#include <bits/stdc++.h>
using namespace std;

struct Patch {
	int pos;
	int taste;
	bool operator <(const Patch& other) {
		return pos < other.pos;
	}
};

struct Bound {
	int pos;
	int gain;
	bool operator <(const Bound& other) {
		if (pos == other.pos) return gain < other.gain;
		else return pos < other.pos;
	};
};


int main() {
	ios::sync_with_stdio(0);
	freopen("in1.in", "r", stdin);
	
	//CHAPTER 1
	
	int k, m, n; 
	cin >> k >> m >> n;
	
	vector<Patch> patches(k);
	for (Patch& patch : patches) {
		cin >> patch.pos >> patch.taste;
	}
	sort(patches.begin(), patches.end());
	
	vector<int> enemies(m);
	for (int& enemy : enemies) {
		cin >> enemy;
	}
	enemies.push_back(INT_MAX);
	sort(enemies.begin(), enemies.end());
	
	vector<Bound> bounds;
	
	int pI = 0;
	int eI = 0;
	while (pI < k) {
		Patch& patch = patches[pI];
		
		if (abs(patch.pos - enemies[eI]) >= abs(patch.pos - enemies[eI+1])) {
			eI++;
		} else {
			int radius = abs(patch.pos - enemies[eI]);
			if (patch.pos > enemies[eI]) {
				bounds.push_back({patch.pos + radius, -patch.taste});
			}
			bounds.push_back({patch.pos - radius, +patch.taste});
			pI++;
		}
	}
	
	sort(bounds.begin(), bounds.end());
	
	
	//for (Bound bound : bounds) {
	//	cout << "pos: " << bound.pos << " gain; " << bound.gain << endl;
	//}
	//cout << endl << endl;
	
	//CHAPTER 2
	
	vector<int64_t> tasteGains;
	
	int bI = 0;
	eI = 0;
	int rightEnemy = enemies[eI];
	int64_t runningGain = 0;
	int64_t singleGain = 0;
	int64_t doubleGain = 0;
	
	while (bI < (int) bounds.size()) {
		
		Bound bound = bounds[bI];
		
		if (bound.pos >= rightEnemy) {
			tasteGains.push_back(doubleGain - singleGain);
			tasteGains.push_back(singleGain);
			eI++;
			rightEnemy = enemies[eI];
			//cout << "TOTAL GAIN : " << doubleGain << endl;
			runningGain = 0;
			singleGain = 0;
			doubleGain = 0;
			
		} else {
			if (bound.gain > 0) doubleGain += bound.gain;
			runningGain += bound.gain;
			singleGain = max(singleGain, runningGain);
			bI++;
		}
		//cout << "pos : " << bound.pos << " runningGain: " << runningGain << endl;
	}
	tasteGains.push_back(doubleGain - singleGain);
	tasteGains.push_back(singleGain);
	//cout << endl;
	sort(tasteGains.begin(), tasteGains.end(), greater<int>());
	
	int64_t totalTasteGain;  // BUG BUG = 0;
	
	for (int i=0; i<n; i++) {
		totalTasteGain += tasteGains[i];
		//cout << tasteGains[i] << " " << endl;
	}
	//cout << endl;
	cout << totalTasteGain;
			
	return 0;
}
