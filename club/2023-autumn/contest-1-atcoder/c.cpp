#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s; cin >> s;
	
	int total = 0;
	
	for (int i = s.size() - 1; i >= 0; i--) {
		cout << i << '\n';
		total += (s[i] - 'A' + 1) * pow(26, i);
	}
	
	cout << total << '\n';
}
