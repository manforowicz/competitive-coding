#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	//freopen("in.in", "r", stdin);
	
	int n, goal; cin >> n >> goal;
	
	vector<int> coins(n);
	vector<int> waysForSum(goal+1);
	waysForSum[0] = 1;
	
	for (int &coin : coins) {
		cin >> coin;
	}
	sort(coins.begin(), coins.end());
	
	
	for (int coin : coins) {
		for (int i=coin; i<=goal; i++) {
			waysForSum[i] += waysForSum[i-coin];
			waysForSum[i] %= 1000000007;
		}
	}
	
	cout << waysForSum[goal];
			
		
	
	return 0;
}
