#include <bits/stdc++.h>
using namespace std;

int main() {
	int64_t n, divisor; cin >> n >> divisor;
	
	unordered_map<int64_t, int64_t> quotients; // {quotient, amount}
	
	for (int64_t i = 0; i < n; i++) {
		int64_t num; cin >> num;
		int64_t quotient = num / divisor;
		if (quotients.find(quotient) == quotients.end()) {
			quotients.insert({quotient, 1});
		} else {
			quotients.at(quotient)++;
		}
		
	}
	
	int64_t pairs = 0;
	for (auto const& x : quotients) {
		pairs += x.second * (x.second-1) / 2;
	}
	
	cout << pairs;
}
		
	
	
