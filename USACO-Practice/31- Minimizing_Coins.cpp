#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	//freopen("Minimizing_Coins.in", "r", stdin);
	int types, goal; cin >> types >> goal;
	
	vector<int> values(types);
	for (int &value : values) cin >> value;
	std::sort(values.rbegin(), values.rend());
	
	vector<int> weights(goal+1, 1000001);
	weights[0] = 0;
	
	for (int sum=1; sum<=goal; sum++) {
		
		for (int value : values) {
			if (value <= sum and weights[sum-value]+1 < weights[sum]) {
				weights[sum] = weights[sum-value] + 1;
			} 
		}
	}
	
	if (weights[goal] == 1000001) cout << -1;
	else cout << weights[goal];
	
	return 0;
}
