#include <bits/stdc++.h>
using namespace std;

int main() {
	int p, a, b, c, d, n; cin >> p >> a >> b >> c >> d >> n;
	
	double highest_price = 0;
	double greatest_drop = 0;
	
	for (int k = 1; k <= n; k++) {
		double price = p * (sin(a * k + b) + cos(c * k + d) + 2);
		highest_price = max(highest_price, price);
		greatest_drop = max(greatest_drop, highest_price - price);
	}
	cout << std::fixed << setprecision(8) << greatest_drop;
}
