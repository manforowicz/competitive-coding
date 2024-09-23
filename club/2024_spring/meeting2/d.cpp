#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// read input
	
	int n; cin >> n;
	vector<int64_t> heros(n);
	
	int64_t hero_sum = 0;
	for (int64_t& hero : heros) {
		cin >> hero;
		hero_sum += hero;
	}
	
	sort(heros.begin(), heros.end());
	
	int m; cin >> m;
	
	for (int i = 0; i < m; i++) {
		int64_t defense, attack; cin >> defense >> attack;
		
		auto overpowered = lower_bound(heros.begin(), heros.end(), defense);
		auto underpowered = upper_bound(heros.begin(), heros.end(), defense);

		int64_t option1;
		if (overpowered == heros.end()) {
			option1 = numeric_limits<int64_t>::max();
		} else {
			int64_t castle_power = hero_sum - *overpowered;
			option1 = max((int64_t) 0, attack - castle_power);
		}
		
		int64_t option2;
		if (underpowered == heros.begin()) {
			option2 = numeric_limits<int64_t>::max();
		} else {
			underpowered -= 1;
			int64_t castle_power = hero_sum - *underpowered;
			option2 = max((int64_t) 0, attack - castle_power) + (defense - *underpowered);
		}
			
		cout << min(option1, option2) << '\n';
	}
}
