#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	freopen("threesum.in", "r", stdin);
	//freopen("threesum.out", "w", stdout);
	
	
	int n, q; cin >> n >> q;
	
	vector<int> list(n+1);
	
	
	for (int i=1; i<=n; i++) {
		int in; cin >> in;
		list[i] = in;
		
	}
	
	set<int> lefts;
	vector<int> numCuttingAt[n-1];
	
	for (int a=1; a <= n-2; a++) {
		
		for (int b= a+1; b <= n-1; b++) {
			int thirdValue = -(list[a]+list[b]);
			
			for (int c = b+1; c <= n; c++){
				
				if (list[c] == thirdValue) {
					ranges.push_back({a, c});
				}
			}
		}
	}
	
	for (int i=0; i<q; i++) {
		int lower, upper; cin >> lower >> upper;
		int counter = 0;
		
		for (pair<int, int> &pair : ranges) {
			if (pair.first >= lower and pair.second <= upper) {
				counter++;
			}
		}
		cout << counter << endl;
	}

	return 0;
}
