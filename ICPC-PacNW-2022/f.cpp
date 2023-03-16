// F: Food Processor
// http://acmicpc-pacnw.org/ProblemSet/Spring2023/pacnw_div1.pdf
// SOLVED (According to sample cases)

#include <bits/stdc++.h>
using namespace std;

// A struct (a simple class) representing a Blade.
struct Blade {
	// Max food piece size this blade can work on.
	int64_t size;
	
	// Time this blade takes to halve the piece size.
	int64_t halve_time;
	
	// Allows blades to be compared with each other using "<".
	// We say the blade of greater "size" is actually smaller.
	// This tricks sort() to order from greatest to smallest.
	bool operator < (const Blade &other) const {
		return size > other.size;
	}
	
	// Lets us compare blade size using "==" for convinience.
	bool operator == (const Blade &other) const {
		return size == other.size;
	}
};

int main() {
	// Magic C++ stuff that makes input/output faster
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("in.txt", "r", stdin);
	
	// Sets doubles to be outputted to 17 decimal places.
	cout << std::fixed << setprecision(17);
	
	int64_t size, target_size, n; cin >> size >> target_size >> n;
	
	// Make vector (ArrayList) of Blades.
	vector<Blade> blades(n);
	
	// "&" tells C++ to loop over references to each Blade.
	// Filling each blade with its info.
	for (Blade &b : blades) {
		cin >> b.size >> b.halve_time;
	}
	
	// Pretend the target food size is also blade.
	// This will make things simpler.
	Blade target = {target_size, 0}; // struct constructor
	blades.push_back(target); // adding to vector
	
	// Sorts blades by their max piece size from greatest to smallest.
	sort(blades.begin(), blades.end());
	
	
	// If the largest blade is too small for the start food size
	// prints -1 and ends program.
	Blade current = blades[0];
	if (current.size < size) {
		cout << -1;
		return 0; // Ends program.
	}
	
	// Sets "current" to the fastest blade that's
	// larger than the start food size.
	int i = 1;
	while (blades[i].size >= size) {
		if (blades[i].halve_time < current.halve_time) {
			current = blades[i];
		}
		i++;
	}
	
	// Stores the total time we've spend slicing food.
	double time = 0;
	
	// Keep slicing with the best blade currently available
	// until we reach the target.
	while (!(current == target)) {
		
		// Find the next blade with a better halve_time,
		// or the target (whichever comes first).
		Blade next = target;
		while (!(blades[i] == target || blades[i].halve_time < current.halve_time)) {
			i++;
		}
		next = blades[i];
		
		// Increment by the time it takes to decrease the piece size
		// to be small enough for the next chosen blade.
		time += current.halve_time * log((double) next.size / current.size) / log(0.5);
		
		// The next blade becomes the current.
		current = next;	
	}
	
	cout << time;
}
