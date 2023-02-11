#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> linkNums(n+1);
	
	for (int i = 0; i < 2*(n-1); i++) {
		int node; cin >> node;
		linkNums[node]++;
	}
	linkNums[1]++;
	int days = n-1;
	for (int i = 1; i <= n; i++) {
		days += ceil(log2(linkNums[i]));
	}
	cout << days;
	return 0;
}
