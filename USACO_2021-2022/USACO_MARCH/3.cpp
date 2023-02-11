#include <bits/stdc++.h>
using namespace std;

//NOT PERFECTLY EFFICIENT AND BEAUTIFUL. FIX IF HAVE TIME!!!

int main() {
	ios::sync_with_stdio(0);
	//freopen("in.in", "r", stdin);
	string s; cin >> s;
	
	vector<int64_t> Cprefix(s.length()+1);
	vector<int64_t> Oprefix(s.length()+1);
	vector<int64_t> Wprefix(s.length()+1);
	
	for (int i=0; i < (int) s.length(); i++) {
		Cprefix[i+1] = Cprefix[i];
		Oprefix[i+1] = Oprefix[i];
		Wprefix[i+1] = Wprefix[i];
		if (s[i] == 'C') Cprefix[i+1]++;
		if (s[i] == 'O') Oprefix[i+1]++;
		if (s[i] == 'W') Wprefix[i+1]++;
	}

	
	int n; cin >> n;
	
	for (int i=0; i<n; i++) {
		int a, b; cin >> a >> b;
		bool C = (Cprefix[b] - Cprefix[a-1]) % 2 == 1;
		bool O = (Oprefix[b] - Oprefix[a-1]) % 2 == 1;
		bool W = (Wprefix[b] - Wprefix[a-1]) % 2 == 1;
		
		if ((C && !O && !W) or (!C && O && W)) {
			cout << "Y";
		} else {
			cout << "N";
		}
		
	}
	
	return 0;
}
	
