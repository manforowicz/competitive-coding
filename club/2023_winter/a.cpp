#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("teleport.in", "r", stdin);
	freopen("teleport.out", "w", stdout);
	
	int a, b, x, y; cin >> a >> b >> x >> y;
	
	int direct = abs(a - b);
	int teleport1 = abs(x - a) + abs(y - b);
	int teleport2 = abs(x - b) + abs(y - a);
	
	int best = min(direct, min(teleport1, teleport2));
	
	cout << best << endl;
}
