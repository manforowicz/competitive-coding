#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x, y, val;
};

auto xCmp = [](const Point& a, const Point& b) {
	if (a.x == b.x) return (a.y < b.y);
	else return (a.x < b.x);
};

auto yCmp = [](const Point& a, const Point& b) {
	if (a.y == b.y) return (a.x < b.x);
	else return (a.y < b.y);
};

int main() {
	//freopen("in.in", "r", stdin);
	
	int n; cin >> n;
	
	vector<Point> cows;
	vector<Point> apples;
	
	for (int i=0; i<n; i++) {
		int q, t, x, num; cin >> q >> t >> x >> num;
		Point point = {t+x, t-x, num};
		if (q == 1) cows.push_back(point);
		if (q == 2) apples.push_back(point);
	}
	sort(cows.begin(), cows.end(), yCmp);
	sort(apples.begin(), apples.end(), yCmp);
	
	int total = 0;
	set<Point, decltype(xCmp)> cowsUnderMe(xCmp);
	
	int appleI = 0;
	int closestCowI = 0;
	
	while (appleI < (int) apples.size()) {
		Point& apple = apples[appleI];
		
		if (closestCowI < (int) cows.size() && cows[closestCowI].y <= apple.y) {
			cowsUnderMe.insert(cows[closestCowI]);
			closestCowI++;
			continue;
		}
		
		
		auto cowI = cowsUnderMe.upper_bound(apple);
		if (cowI == cowsUnderMe.begin()) {
			appleI++;
			continue;
		}
		cowI--;
		
		Point cow = *cowI;
		if (cow.val > apple.val) {
			total += apple.val;
			cow.val -= apple.val;
			appleI++;
			cowsUnderMe.erase(cowI);
			cowsUnderMe.insert(cow);
		} else {
			total += cow.val;
			apple.val -= cow.val;
			cowsUnderMe.erase(cowI);
		}
		
		
	}
	
	cout << total;
}
