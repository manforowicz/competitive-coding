#include <bits/stdc++.h>
using namespace std;

struct Blade {
	int m, h;
	
	bool operator < (const Blade &other) const {
		return m > other.m;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("in.txt", "r", stdin);
	cout << std::fixed << setprecision(17);
	
	int size, target, n; cin >> size >> target >> n;
	
	vector<Blade> blades(n);
	
	for (Blade &b : blades) {
		cin >> b.m >> b.h;
	}
	
	// sort blades from largest to smallest
	sort(blades.begin(), blades.end());
	
	
	// find best blade that isn't too small
	Blade best = blades[0];
	if (blades[0].m < size) {
		cout << -1;
		return 0;
	}
	
	int i = 0;
	while (i+1 < n && blades[i+1].m >= size) {
		i++;
		if (blades[i].h < best.h) {
			best = blades[i];
		}
	}
	
	double time = 0;
	
	while (size > target) {
		
		// determine next size to decrease to
		int nextSize = target;
		while (i+1 < n) {
			i++;
			if (target < blades[i].m && blades[i].h < best.h) {
				nextSize = blades[i].m;
				break;
			}
			
		}
		
		time += best.h * log((double) nextSize / size) / log(0.5);
		size = nextSize;
		
		best = blades[i];
			
	}
	cout << time;
}
