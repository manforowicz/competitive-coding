#include <bits/stdc++.h>
using namespace std;

vector<double> polynomial;

double getVolume(double a, double b) {
	double volume = 0;
	for (size_t i = 0; i < polynomial.size(); i++) {
		volume += polynomial[i] / (i+1) * (pow(b, i+1) - pow(a, i+1));
	}
	return M_PI * volume;
}

double getPosOfVolume(double volume, double low, double high) {
	double upper = high;
	double lower = low;
	while (upper - lower > 0.00001) {
		double mid = (upper + lower) / 2;
		if (getVolume(low, mid) > volume) {
			upper = mid;
		} else {
			lower = mid;
		}
	}
	return upper;
}

vector<double> square(vector<double> polynomial) {
	vector<double> squared(polynomial.size() * 2);
	for (size_t i = 0; i < polynomial.size(); i++) {
		for (size_t j = 0; j < polynomial.size(); j++) {
			squared [i+j] += polynomial[i] * polynomial[j];
		}
	}
	return squared;
}


int main() {
	int case_num = 1;
	int n;
	while (cin >> n) {
		polynomial.clear();
		for (int i = 0; i <= n; i++) {
			double coefficient; cin >> coefficient;
			polynomial.push_back(coefficient);
		}
		polynomial = square(polynomial);
		
		double low, high, inc; cin >> low >> high >> inc;
		
		double total_volume = getVolume(low, high);
		
		cout << "Case " << case_num << ": " << std::fixed << setprecision(2) << total_volume << '\n';
		
		if (inc > total_volume) {
			cout << "insufficient volume\n";
		} else {
			double volume = inc;
			for (int i = 0; i < 8 && volume < total_volume; i++) {
				double mark = getPosOfVolume(volume, low, high) - low;
				cout << std::fixed << setprecision(2) << mark << ' ';
				volume += inc;
			}
			cout << '\n';
		}
		case_num++;
	}
	
}
		
