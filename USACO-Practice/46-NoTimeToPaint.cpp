#include <bits/stdc++.h>
using namespace std;


vector<int> makePrefix(string s) {
	stack<char> paint;
	vector<int> prefix(s.size()+1);
	
	for (int i=0; i < (int) s.size(); i++) {
		prefix[i+1] = prefix[i];
		while (!paint.empty() and paint.top() > s[i]) {
			paint.pop();
		}
		if (paint.empty() or paint.top() < s[i]) {
			paint.push(s[i]);
			prefix[i+1]++;
		}
		
	}
	
	return prefix;
}


int main() {
	ios::sync_with_stdio(0);
	//freopen("in.in", "r", stdin);
	
	string s; int n, q; cin >> n >> q >> s;
	//cout << s << endl;
	vector<int> prefix = makePrefix(s);
	for (int i : prefix) {
	//	cout << i;
	}
	//cout << endl;
	reverse(s.begin(), s.end());
	vector<int> suffix = makePrefix(s);
	
	for (int i=0; i<q; i++) {
		int a, b; cin >> a >> b;
		cout << prefix[a-1] + suffix[n-b] << endl;
	}
	
	return 0;
}
