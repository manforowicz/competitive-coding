#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, k; cin >> n >> m >> k;
	
	vector<int> stack_a(n);
	vector<int> stack_b(m);
	
	for (int &elem : stack_a) {
		cin >> elem;
	}
	
	for (int &elem: stack_b) {
		cin >> elem;
	}
}
