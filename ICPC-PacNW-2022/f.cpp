// F: Food Processor
// http://acmicpc-pacnw.org/ProblemSet/Spring2023/pacnw_div1.pdf
// SOLVED (According to sample cases)

#include <bits/stdc++.h>
using namespace std;

// A struct (Class) representing a Blade
struct Blade {
	// Max piece size this blade works on
	int64_t max_size;
	
	// Time this blade takes to halve the piece size
	int64_t halve_time;
	
	// Allows blades to be compared with each other using <
	// We say the blade of greater max_size is smaller.
	// This tricks sort() to order blades
	// by max_size from greatest to smallest.
	bool operator < (const Blade &other) const {
		return max_size > other.max_size;
	}
};

int main() {
	// Magic C++ stuff that makes input/output faster
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("in.txt", "r", stdin);
	
	// Sets doubles to be outputted to 17 decimal places.
	cout << std::fixed << setprecision(17);
	
	int64_t size, target, n; cin >> size >> target >> n;
	
	// Make vector (ArrayList) of Blades.
	vector<Blade> blades(n);
	
	// & tells C++ to loop over references to each Blade.
	for (Blade &b : blades) {
		cin >> b.max_size >> b.halve_time;
	}
	
	// Sorts blades by max_size from greatest to smallest.
	sort(blades.begin(), blades.end());
	
	
	// find best blade that isn't too small
	Blade best = blades[0];
	if (blades[0].max_size < size) {
		cout << -1;
		return 0;
	}
	
	int i = 0;
	while (i+1 < n && blades[i+1].max_size >= size) {
		i++;
		if (blades[i].halve_time < best.halve_time) {
			best = blades[i];
		}
	}
	
	double time = 0;
	
	while (size > target) {
		
		// determine next size to decrease to
		int nextSize = target;
		while (i+1 < n) {
			i++;
			if (target < blades[i].max_size && blades[i].halve_time < best.halve_time) {
				nextSize = blades[i].max_size;
				break;
			}
			
		}

		time += best.halve_time * log((double) nextSize / size) / log(0.5);
		size = nextSize;
		
		best = blades[i];
			
	}
	cout << time;
}
