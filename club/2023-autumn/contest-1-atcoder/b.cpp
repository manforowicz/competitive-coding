#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	
	string s; cin >> s;
	
	for (int i = 1; i < n; i++) {
		int l = 0;
		while (l + i < n && s[l] != s[l+i]) {
			l += 1;
		}
		cout << l << '\n';		
	}
}
