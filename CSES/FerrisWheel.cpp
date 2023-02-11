#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

int main() {
	set<int> children;
	
	int n, x; cin >> n >> x;
	
	for (int num : children) {
		children.erase(children.upper_bound(x - num) -- );
	}
}
