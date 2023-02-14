#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<int64_t> prefix(n+2);
	
	for (int i = 0; i < k; i++) {
		char type; cin >> type;
		int64_t a, b; cin >> a >> b;
		
		if (type == 'R') {
			prefix[a-1] += 1;
			prefix[a] -= 1;
			prefix[b] -= 1;
			prefix[b+1] += 1;
			
		} else if (type == 'D') {
			prefix[a-1] -= 1;
			prefix[a] += 1;	
			prefix[b] += 1;
			prefix[b+1] -= 1;
			
		} else if (type == 'H') {
			prefix[a-1] += 1;
			
			prefix[(a + b)/2] -= 1;
			prefix[(a + b + 1)/2] -= 1;
			
			prefix[b+1] += 1;
			
		} else if (type == 'V') {
			prefix[a-1] -= 1;
			
			prefix[(a + b)/2] += 1;
			prefix[(a + b + 1)/2] += 1;
			
			prefix[b+1] -= 1;
		}
	}
	
	int64_t slope = 0;
	int64_t pos = 0;
	
	for (int i = 0; i < n; i++) {
		slope += prefix[i];
		pos += slope;
		cout << pos << '\n';
	}
}
