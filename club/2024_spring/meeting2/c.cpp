#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	
	vector<int> arr(n + 1);
	
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	int64_t counter1 = 0;
	int64_t counter2 = 0;
	
	for (int i = 1; i <= n; i++) {
		if (arr[i] == i) {
			counter1 += 1;
		} else if (i == arr[arr[i]]) {
			counter2 += 1;
		}
	}
	
	int64_t answer = counter2 / 2 + (counter1 * (counter1 - 1)) / 2;
	cout << answer << '\n';
}
