#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	//freopen("in1.in", "r", stdin);
	int n, m; cin >> n >> m;
	
	vector<int64_t> leftFreqs(m+1), rightFreqs(m+1);
	
	for (int i=0; i<n; i++) {
		int left, right; cin >> left >> right;
		leftFreqs[left]++;
		rightFreqs[right]++;
	}
	
	vector<int64_t> changeAtK(2*m + 2);
	
	for (int i=0; i<=m; i++) {
		for (int j=0; j<=m; j++) {
			changeAtK[i+j] += leftFreqs[i] * leftFreqs[j];
			changeAtK[i+j+1] -= rightFreqs[i] * rightFreqs[j];
		}
	}
	
	int64_t combinations = 0;
	for (int i=0; i<=2*m; i++) {
		combinations += changeAtK[i];
		cout << combinations << endl;
	}
	
	return 0;
}
