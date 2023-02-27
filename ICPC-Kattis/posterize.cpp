#include <bits/stdc++.h>
using namespace std;

// didn't finish

struct Color {
	int pos;
	int amount;
};

vector<Color> histogram;

int64_t cost(int left, int right, int pos) {
	int64_t sum = 0;
	for (Color c : histogram) {
		if (left <= c.pos && c.pos <= right) {
			sum += c.amount * pow(pos - c.pos, 2);
		}
	}
	return sum;
		
}

int64_t cost(int left, int right) {
	int64_t a = cost(left, right, left);
	int64_t b = cost(left, right, left+1);
	int64_t c = cost(left, right, left+2);
	int64_t second_derivative = (c-b) - (b-a);
	int64_t slope = (c - a)/2;
	if (slope == 0) {
		return cost(left, right, b);
	}
	int64_t optimal = b + slope / second_derivative;
	return cost(left, right, optimal);
}
	

int main() {

	
	
	
	int d, k; cin >> d >> k;
	
	for (int i = 0; i < d; i++) {
		int pos, amount; cin >> pos >> amount;
		histogram.push_back({pos, amount});
	}
	
	vector<vector<int64_t>> costs(256, vector<int64_t>(256)); // [left][right]
	for (int left = 0; left < 256; left++) {
		for (int right = left; right < 256; right++) {
			costs[left][right] = cost(left, right);
			cout << cost(left, right) << endl;
		}
	}
	
	vector<vector<int64_t>> minCost(256, vector<int64_t>(256)); // [number of chosen][right]
	
	for (int numOfChosen = 1; numOfChosen < k; numOfChosen++) {
		for (int right = 1; right < 256; right++) {
			minCost[numOfChosen][right] = numeric_limits<uint64_t>::max();
			for (int left = 0; left < right; left++) {
				minCost[numOfChosen][right] = min(minCost[numOfChosen][right], minCost[numOfChosen-1][left] + costs[left][right]);
			}
		}
	}
	cout << minCost[k][255];
}
