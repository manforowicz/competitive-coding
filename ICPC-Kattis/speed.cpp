#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << std::fixed << setprecision(7);
	
	int n, t; cin >> n >> t;
	
	vector<int> distances(n);
	vector<int> speeds(n);
	
	int total_distance = 0;
	for (int i = 0; i < n; i++) {
		cin >> distances[i];
		cin >> speeds[i];
		
		total_distance += distances[i];
	}
	
	int slowest = *min_element(speeds.begin(), speeds.end());
	
	double upper = (double) total_distance/t - slowest;
	double lower = -slowest;
	
	
	while (upper - lower > 10e-8) {
		//cout << lower << ' ' << upper << '\n';
		double c_guess = (upper + lower) / 2;
		
		double time = 0;
		for (int i = 0; i < n; i++) {
			time += distances[i] / (speeds[i] + c_guess);
		}
		//cout << time << '\n';
		if (time > t) {
			lower = c_guess;
		} else {
			upper = c_guess;
		}
		
	}
	
	cout << upper;
	
	
}
