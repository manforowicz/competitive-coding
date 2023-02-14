#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> links(26);
vector<bool> visited(26);

bool find_letter(int a, int b) {
	if (a == b) {
		return true;
	}
	if (visited[a]) {
		return false;
	}
	visited[a] = true;
	
	for (int next : links[a]) {
		if (find_letter(next, b)) {
			return true;
		}
	}
	return false;
}

bool translatable(string a, string b) {
	if (a.size() != b.size()) {
		return false;
	}
	for (int i = 0; i < (int) a.size(); i++) {
		visited = vector<bool>(26);
		if (!find_letter(a[i] - 'a', b[i] - 'a')) {
			return false;
		}
	}
	return true;
}


int main() {
	int m, n; cin >> m >> n;
	
	
	
	for (int i = 0; i < m; i++) {
		char a, b;
		cin >> a >> b;
		links[a - 'a'].push_back(b - 'a');
	}
	
	for (int i = 0; i < n; i++) {
		string a, b; cin >> a >> b;
		if (translatable(a, b)) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
				
	}
}
