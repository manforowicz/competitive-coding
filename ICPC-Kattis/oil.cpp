#include <bits/stdc++.h>
using namespace std;

// giving up. Don't know why it's not working

pair<int64_t, int64_t> pivot;

struct Point {
	int64_t x, y;
	int64_t price;
	bool right;
	
	bool is_entry() const {
		return (right) == (y < pivot.second);
	}
	
	bool operator < (const Point &other) const {
		
		if (other.y == pivot.second || y == pivot.second) {
			return false;
		}
		
		double slope = (double) (x - pivot.first) / (y - pivot.second);
		double o_slope = (double) (other.x - pivot.first) / (other.y - pivot.second);
		
		if ((x - pivot.first)*(other.y-pivot.second) == (other.x-pivot.first)*(y-pivot.second)) {
			if (is_entry() != other.is_entry()) {
				return is_entry();
			} else {
				return false;
			}
		}
		return slope < o_slope;
	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	vector<Point> points;
	
	for (int i = 0; i < n; i++) {
		int64_t x0, x1, y; cin >> x0 >> x1 >> y;
		int64_t left = min(x0, x1);
		int64_t right = max(x0, x1);
		int64_t price = right - left;
		points.push_back({left, y, price, false});
		points.push_back({right, y, price, true});
	}
	
	vector<Point> sortedPoints = points;
	
	int64_t max_money = 0;
	for (const Point &pivot_point : points) {
		pivot = {pivot_point.x, pivot_point.y};
		sort(sortedPoints.begin(), sortedPoints.end());
		int64_t money = pivot_point.price;
		for (int i = 0; i < n; i++) {
			const Point &p = sortedPoints[i];
			if (p.y != pivot.second) {
				if (p.is_entry()) {
					money += p.price;
				} else {
					money -= p.price;
				}
			}
			max_money = max(max_money, money);
		}
	}
	cout << max_money;
}
