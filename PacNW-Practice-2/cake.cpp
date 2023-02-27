#include <bits/stdc++.h>
using namespace std;

int main() {
	int64_t length, cut1, cut2; cin >> length >> cut1 >> cut2;
	
	cout << 4 * max(cut1, length-cut1) * max(cut2, length-cut2);
}
