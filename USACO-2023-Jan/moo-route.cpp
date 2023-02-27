#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	
	vector<int> world(n+2);
	world[0] = 1;
	
	for (int i = 0; i < n; i++) {
		cin >> world[i+1];
	}
	world.back() = 0;
	
	int right_bound = n;
	int pointer = 0;
	char dir = 'R';
	
	// left is world[pointer]
	// right is world[pointer+1]
	
	while (right_bound != 0) {
		if (dir == 'R') {
			if (right_bound == pointer) {
				dir = 'L';
			}
		} else {
			if (world[pointer] == 1 && right_bound != pointer) {
				dir = 'R';
			}
		}
		
		cout << dir;
		if (dir == 'R') {
			pointer++;
			world[pointer] -= 1;
		} else {
			world[pointer] -= 1;
			pointer--;
		}
		
		
		if (world[pointer+1] == 0) {
			right_bound = pointer;
		}
	}
}
