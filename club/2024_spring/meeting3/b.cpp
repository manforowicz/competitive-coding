#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	
	for (int test = 0; test < t; test++) {
		int64_t xA, yA; cin >> xA >> yA;
		int64_t xB, yB; cin >> xB >> yB;
		int64_t xC, yC; cin >> xC >> yC;
		
		int64_t b_x_diff = xA - xB;
		int64_t b_y_diff = yA - yB;
		int64_t c_x_diff = xA - xC;
		int64_t c_y_diff = yA - yC;
		
		
		int64_t result = 1;
		
		if ((b_x_diff > 0) == (c_x_diff > 0)) {
			result += min(abs(b_x_diff), abs(c_x_diff));
		}
		
		if ((b_y_diff > 0) == (c_y_diff > 0)) {
			result += min(abs(b_y_diff), abs(c_y_diff));
		}
		cout << result << '\n';
	}
}
