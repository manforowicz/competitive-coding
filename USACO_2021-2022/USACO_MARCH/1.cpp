#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<int> link;
vector<int> value;
int64_t totalMoos;

void explore(int i) {
	vector<int> path;
	
	while (!visited[i]) {
		path.push_back(i);
		visited[i] = true;
		i = link[i];
	}
	
	auto it = find(path.begin(), path.end(), i);
	if (it == path.end()) return;
	
	i = it - path.begin();
	int minMoos = INT_MAX;
	while (i < (int) path.size()) {
		minMoos = min(minMoos, value[path[i]]);
		i++;
	}
	
	totalMoos -= minMoos;
}

int main() {
	ios::sync_with_stdio(0);
	
	int n; cin >> n;
	
	visited.resize(n+1);
	link.resize(n+1);
	value.resize(n+1);
	
	for (int i=1; i<=n; i++) {
		cin >> link[i];
		cin >> value[i];
		totalMoos += value[i];
	}
	
	for (int i=1; i<=n; i++) {
		if (!visited[i]) explore(i);
	}
	
	cout << totalMoos;	
	
	
	return 0;
}
	
