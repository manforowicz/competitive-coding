#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, l, r; cin >> n >> l >> r;
	
	int64_t zero_numbers = (r - l) / 3;
	int64_t one_numbers = (r - l) / 3;
	int64_t two_numbers = (r - l) / 3;
	
	int64_t zero_sums = 1;
	int64_t one_sums = 0;
	int64_t two_sums = 0;
	
	for (int i = 0; i < n; i++) {
		int64_t new_zero_sums = zero_sums * zero_numbers + one_sums * two_numbers  + two_sums * one_numbers;
		int64_t new_one_sums  = zero_sums * one_numbers  + one_sums * zero_numbers + two_sums * two_numbers;
		int64_t new_two_sums  = zero_sums * two_numbers  + one_sums * one_numbers  + two_sums * zero_numbers;
		
		zero_sums = new_zero_sums % 1000000007;
		one_sums = new_one_sums % 1000000007;
		two_sums = new_two_sums % 1000000007;
	}
	
	cout << zero_sums << endl;
	
	
	
	
	
}
