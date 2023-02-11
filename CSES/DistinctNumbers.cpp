#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;
	
	vector<bool> viewed(1e9 + 1);
	
	int count = 0;
	for (int i=0; i<n; i++) {
		int num; cin >> num;
		if (!viewed[num]) {
			count++;
			viewed[num] = true;
		}
	}
	cout << count;
	return 0;
}
