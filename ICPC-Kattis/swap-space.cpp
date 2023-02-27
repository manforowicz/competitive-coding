#include <bits/stdc++.h>
using namespace std;

struct Drive {
	int64_t a, b;
	
	bool operator < (const Drive &other) const {
		bool gain = b > a;
		bool o_gain = other.b > other.a;
		if (gain) {
			if (o_gain) {
				return a < other.a;
			} else {
				return true;
			}
		} else {
			if (o_gain) {
				return false;
			} else {
				return b > other.b;
			}
		}
	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	
	vector<Drive> drives(n);
	
	for (int i = 0; i < n; i++) {
		int64_t a, b; cin >> a >> b;
		drives[i] = {a, b};
	}
	sort(drives.begin(), drives.end());
	
	int64_t lowest_spare = 0;
	int64_t spare = 0;
	
	
	for (const Drive &drive : drives) {
		lowest_spare = min(lowest_spare, spare-drive.a);
		spare += drive.b - drive.a;
	}
	
	cout << -lowest_spare;
}
