#include <iostream>
#include <set>
using namespace std;

int main() {	
	// Read n from standard input.
    int n; cin >> n;
	
	// Will store the distinct
	// numbers seen so far.
	set<int> seen;
	
	// Repeat n times.
	for (int i = 0; i < n; i++) {

		// Read the next number.
		int num; cin >> num;
		
		// Add it to our set.
		// Does nothing if it's
		// already in the set.
		seen.insert(num);
	}
	
	// Output the size of our set.
	// This is the number of distinct
	// numbers we've seen.
	cout << seen.size() << '\n';
}
