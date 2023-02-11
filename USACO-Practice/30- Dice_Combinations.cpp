#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	//freopen("Dice_Combinations.in", "r", stdin);
	int n; cin >> n;
	
	vector<long long> perms(n+1);
	perms[0] = 1;
	for (int sum=1; sum<=n; sum++) {
		for (int lastRoll = 1; lastRoll<=6 and lastRoll <= sum; lastRoll++) {
			perms[sum] += perms[sum-lastRoll];
			perms[sum] %= 1000000007;
		}
	}
	
	cout << perms.back();
	
	return 0;
}
