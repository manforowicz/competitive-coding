#include <bits/stdc++.h>
using namespace std;

int main() {
	string a; cin >> a;
	string b; cin >> b;
	
	int count = 1;
	for (int i = 0; i < 4; i++) {
		if (a[i] != b[i]) {
			count *= 2;
		}
	}
	cout << count;
}
