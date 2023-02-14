#include <bits/stdc++.h>
using namespace std;

 // UNSOLVED

struct Hole {
	double r;
	double z;
};


double get_volume_at(double z) {
	
}


int main() {
	int n, s; cin >> n >> s;
	
	vector<Hole> holes;
	double volume = 1000 * 1000 * 1000;

	
	for (int i = 0; i < n; i++) {
		double r, _x, _y, z; cin >> r >> _x >> _y >> z;
		
		r /= 1000;
		z /= 1000;
		
		volume -= M_PI * 4/3 * pow(r, 3);
		holes.push_back({r, z}); 
		holes.push_back({r, z}); 

	}
	
	volume /= s; // now represents the volume per slice
	
	vector<double> radii;
	
	double curr_slice_v = 0;
	for (int i = 0; i < s; i++) {
		while (condition) {
		}
			
	}
	
	
	
	
	
}
	
