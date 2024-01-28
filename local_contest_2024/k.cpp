// K

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// freopen("a.in", "r", stdin);
	
	vector<char> v = {'0', 'A', 'B', '0', '0', '0', 'C', 'D', 'E', '0', 'F', 'G', 'H', 'I',
		'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', '0', 'U', 'V', 'W', '0', '0',
		'X', 'Y', '0', '0', '0', '0', 'Z', '0', '0'};
		
	map<string, int> mp; 
	for (int i = 0; i < (int) v.size(); i++) {
		for (int j = i; j < (int) v.size(); j++) {
			if (v[i] == '0' || v[j] == '0') continue;
			string k1 = "";
			k1 += v[i];
			k1 += v[j];
			string k2 = "";
			k2 += v[j];
			k2 += v[i];
			cout << k1 << " " << k2 << "\n";
			mp[k1] = abs(i / 5 - j / 5) + abs(i % 5 - j % 5);
			mp[k2] = abs(i / 5 - j / 5) + abs(i % 5 - j % 5);
		}
	}
	
	string s; cin >> s;
	string tempK = "A";
	tempK += s[0];
	int cnt = mp[tempK];
	cout << cnt << "\n";
	for (int i = 1; i < (int) s.size(); i++) {
		string k = "";
		k += s[i - 1];
		k += s[i];
		cnt += mp[k];
		cout << mp[k] << "\n";
	}
	cout << cnt << "\n";
}

