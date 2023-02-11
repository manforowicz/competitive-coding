#include <bits/stdc++.h>
using namespace std;

//The pair means <number, cost to get to goal>
vector<pair<int64_t, int>> getHalves(int64_t dest) {
	vector<pair<int64_t, int>> points;
	int cost = 0;
	while (dest > 1) {
		points.push_back({dest, cost});
		if (dest % 2 != 0) {
			dest--;
			cost++;
		}
		dest /= 2;
		cost++;
	}
	points.push_back({dest, cost});
	points.push_back({0, cost+1});
	reverse(points.begin(), points.end());
	return points;
}



int main() {
	//freopen("in.in", "r", stdin);
	int n; cin >> n;
	
	for (int q=0; q<n; q++) {
		int64_t curr, goal; cin >> curr >> goal;
		int64_t minCost = 1e18;
		vector<pair<int64_t, int>> points = getHalves(goal);
		
		//for (auto& point : points) {
		//	cout << "(" << point.first << ", " << point.second << ")" << " ";
		//}
		//cout << endl << endl;
		
		int i = points.size() - 1;
		int jumps = 0;
		//cout << points.size() << " ";
		
		while (curr > points.back().first) {
			if (curr % 2 != 0) {
				curr++;
				jumps++;
			}
			jumps++;
			curr /= 2;
		}
		
		
		do {
			if (points[i-1].first >= curr) {
				i--;
			} else {
				pair<int64_t, int> point = points[i];
				
				int64_t cost = (point.first - curr) + point.second + jumps;
				//cout << "bu: " << point.first << " " << curr << " ";
				minCost = min(minCost, cost);
				
				if (curr % 2 != 0) {
					curr++;
					jumps++;
				}
				jumps++;
				curr /= 2;
			}
		} while (curr > 1);
		cout << minCost << "\n";
	}
				
	
	
	
	
	
	return 0;
}
