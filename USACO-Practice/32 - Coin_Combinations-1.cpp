#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	//freopen("in.in", "r", stdin);
	
	int n, goal; cin >> n >> goal;
	
	
	vector<int> coins(n);
	vector<long> waysForSum(goal+1);
	waysForSum[0] = 1;
	
	for (int &coin : coins) {
		cin >> coin;
	}
	
	sort(coins.begin(), coins.end());
	
	for (int sum=1; sum<=goal; sum++) {
		
		for (int coin : coins) {
			if (coin > sum) break;
			waysForSum[sum] += waysForSum[sum-coin];
			waysForSum[sum] %= (1000000007);
			
		}
	}
	
	cout << waysForSum[goal];
	
	return 0;
}
	
