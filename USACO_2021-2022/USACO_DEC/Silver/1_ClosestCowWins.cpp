#include <bits/stdc++.h>
using namespace std;

struct Patch {
	int pos;
	int taste;
	int radius = INT_MAX;
	int leftBound;
	int rightBound;
	bool operator < (const Patch& other) {return leftBound < other.leftBound;};
};

struct Value {
	vector<int> positions;
	int val;
	bool operator <(const Value& other) {return val > other.val;};
};

int main() {
	ios::sync_with_stdio(0);
	//freopen("in1.in", "r", stdin);
	
	int k, m, n;
	cin >> k >> m >> n;
	
	vector<Patch> patches(k);
	
	for (Patch& patch : patches) {
		cin >> patch.pos >> patch.taste;
	}
	
	
	vector<int> enemies(m);
	for (int& enemy : enemies) {
		cin >> enemy;
		//cout << enemy << endl;
	}
	//cout << endl;
	
	int patchI = 0;
	int enemyI = 0;
	
	while (patchI < k) {
		Patch& patch = patches[patchI];
		patch.radius = min(patch.radius, abs(patch.pos - enemies[enemyI]));
		patch.leftBound = patch.pos - patch.radius;
		patch.rightBound = patch.pos + patch.radius;
		if (enemies[enemyI] < patch.pos and enemyI < m-1) enemyI++;
		else patchI++;
	}	
	
	sort(patches.begin(), patches.end());
	
	//for (Patch patch : patches) {
	//	cout << "pos: " << patch.pos << " taste: " << patch.taste << " radius: " << patch.radius << " leftBound: " << patch.leftBound << endl;
	//}
	
	
	
	vector<Value> values(k);
	
	for (int i=0; i<k; i++) {
		Patch& patchA = patches[i];
		values[i].val += patchA.taste;
		values[i].positions.push_back(patchA.pos);
		for (Patch& patchB : patches) {
			if ((patchA.leftBound < patchB.rightBound and patchA.leftBound > patchB.leftBound)
				or (patchA.leftBound == patchB.leftBound and patchA.rightBound < patchB.rightBound)) {
				values[i].val += patchB.taste;
				values[i].positions.push_back(patchB.pos);
				//cout << "burp" << endl;
			}
		}
	}
	//cout << endl;
	
	sort(values.begin(), values.end());
	
	set<int> taken;
	
	long long ans = 0;
	
	int count = 0;
	int i = 0;
	while (count < n and i < k) {
		
		bool thing = true;
		for (int pos : values[i].positions) {
			if (taken.find(pos) != taken.end()) {
				thing = false;
			}
		}
		if (thing) {
			for (int pos : values[i].positions) {
			
				taken.insert(pos);
			}
			ans += values[i].val;
			count++;
		}
		//cout << values[i].val << endl;
		i++;
	}
	
	cout << ans;
	return 0;
}
