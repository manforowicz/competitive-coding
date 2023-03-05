#include <bits/stdc++.h>
using namespace std;

// SOLVED (According to sample cases)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int64_t n, k; cin >> n >> k;
	int64_t count = 0;
	int64_t champ = 0;
	
	for (int64_t i = 1; i <= n; i++) {
		int multiplier = pow(10, (int) log10(i) + 1);
		champ = champ * multiplier + i;
		champ %= k;
		
		if (champ == 0) {
			count += 1;
		}
	}
	cout << count;
}
