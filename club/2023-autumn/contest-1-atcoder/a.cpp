#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int a, b; cin >> a >> b;
	
	int a_num = min(a, b);
	int b_num = max(a, b);
	
	if (a_num * 2 == b_num || a_num * 2 + 1 == b_num) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
	
}
