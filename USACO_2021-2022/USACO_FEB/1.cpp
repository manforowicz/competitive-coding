#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> links;
vector<vector<int>> valueOf;
vector<bool> visited;


int dfs(int gift, int cowI) {
	visited[gift] = true;
	int bestValue = valueOf[cowI][gift];
	for (int link : links[gift]) {
		if (!visited[link]) {
			bestValue = min(bestValue, dfs(link, cowI));
		}
	}
	return bestValue;
}


int main() {
	//freopen("in.in", "r", stdin);
	int n; cin >> n;
	links.resize(n+1); //index is gift
	visited.resize(n+1); //index is gift
	valueOf.resize(n+1, vector<int>(n+1)); //index is cow, gift
	vector<vector<int>> cows(n+1, vector<int>(n+1)); // index is cow, value of gift
	
	for (int cow=1; cow<=n; cow++) {
		bool addLink = true;
		for (int value=1; value<=n; value++) {
			int gift; cin >> gift;
			if (gift == cow) addLink = false;
			if (addLink) {
				links[gift].push_back(cow);
			}
			valueOf[cow][gift] = value;
			cows[cow][value] = gift;
		}
		
	}
	
	for (int cowI=1; cowI<=n; cowI++) {
		//for (int num : valueOf[cowI]) {
		//	cout << num << " ";
		//}
		//cout << endl;
		fill(visited.begin(), visited.end(), 0);
		cout << cows[cowI][dfs(cowI, cowI)] << endl;
	}
	
	return 0;
}
