#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	freopen("cereal.in", "r", stdin);
	//freopen("cereal.out", "w", stdout);
	
	int n, m; cin >> n >> m;
	
	vector<int> whichCowHas(m+1, -1);
	
	vector<pair<int, int>> cows(n);
	
	for (auto& cow : cows) {
		cin >> cow.first >> cow.second;
	}
	
	vector<int> answers(n + 1);
	
	for (int headI=n-1; headI>=0; headI--) {
		answers[headI] = answers[headI+1];
		int headFirstC = cows[headI].first;
		int prevI = whichCowHas[headFirstC];
		
		if (prevI == -1) {
			answers[headI]++;
		} else if (cows[prevI].second == headFirstC) {
			//DO NOTHING
		} else {
			int prevSecondC = cows[prevI].second;
			int prev2I = whichCowHas[prevSecondC];
			if (prev2I == -1) {
				answers[headI]++;
			} else if (prev2I > prevI) {
				answers[headI]++;
			}
		}
		whichCowHas[headFirstC] = headI;
	}
	
	for (int i=0; i<n; i++) {
		cout << answers[i] << endl;
	}
	
	return 0;
}
