#include <bits/stdc++.h>
using namespace std;

struct City {
	int id;
	int value;
	int bestProfit = INT_MIN;
	vector<int> links;
	
	bool operator<(const City& other) const {
		return id < other.id;
	}
};

int main() {
	ios::sync_with_stdio(0);
	freopen("time.in", "r", stdin);
	freopen("time.out", "w", stdout);
	
	int n, m, c; cin >> n >> m >> c;
	
	vector<City> cities(n+1);	
	for (int i = 1; i<=n; i++) {
		cin >> cities[i].value;
		cities[i].id = i;
	}
	for (int i=0; i<m; i++) {
		int a, b; cin >> a >> b;
		cities[a].links.push_back(b);
	}

	cities[1].bestProfit = 0;
	
	set<int> next;
	vector<City> prev;
	
	next.insert(1);
	int time = 0;
	
	while (next.size() != 0) {
		
		prev.clear();
		for (int num : next) {
			prev.push_back(cities[num]);
		}
		next.clear();
		
		for (const City& base : prev) {
			
			for (int num : base.links) {
				City &dest = cities[num];
				int newProfit = base.bestProfit + dest.value - c*(time*2+1);
				
				if (newProfit > dest.bestProfit) {
					next.insert(num);
					dest.bestProfit = newProfit;
				}
			}
		}
		time++;
	}
	
	cout << cities[1].bestProfit;
	return 0;
}

