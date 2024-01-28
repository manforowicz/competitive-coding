// J

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// freopen("a.in", "r", stdin);
	
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		int k; cin >> k;
		
		if (k == 1) {
			cout << 0 << "\n"; continue;
		}
		
		if (k == s.size()) {
			int cnt = 0;
			for (int i = 0; i < s.size() / 2; i++) {
				cnt += s[i] != s[s.size() - 1 - i];
			}
			cout << cnt << "\n"; continue;
		}
		
		if (k & 1) {
			map<char, int> odd;
			map<char, int> even;
			
			int oddMax = 0;
			int evenMax = 0;
			
			for (int i = 0; i < s.size(); i++) {
				if (i % 2 == 0) {
					even[s[i]]++;
					evenMax = max(evenMax, even[s[i]]);
				} else {
					odd[s[i]]++;
					oddMax = max(oddMax, odd[s[i]]);
				}
			}
			
			cout << ((s.size() + 1) / 2) - evenMax + (s.size() / 2) - oddMax << "\n"; continue;
		}
		
		map<char, int> mp;
		
		int cnt = 0;
		for (auto &x : s) {
			mp[x]++;
			cnt = max(mp[x], cnt);
		}
		
		cout << s.size() - cnt << "\n";
	}	
}
