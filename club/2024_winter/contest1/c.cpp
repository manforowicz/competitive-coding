#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	
	for (int test = 0; test < t; test++) {
		int n, a, b; cin >> n >> a >> b;
		
		string s;
		
		for (int i = 0; i < n; i++) {
			s.push_back('a' + i % b);
		}
		cout << s << '\n';
	}
}
