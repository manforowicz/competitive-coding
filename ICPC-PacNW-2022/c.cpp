// C: Champernowne Count
// http://acmicpc-pacnw.org/ProblemSet/Spring2023/pacnw_div1.pdf
// SOLVED (According to sample cases)

#include <bits/stdc++.h>
using namespace std;


// Returns how many digits a number has
int countDigits(int64_t num) {
	int64_t digits = 0;
	while (num != 0) {
		digits += 1;
		num /= 10;
	}
	return digits;
}

int main() {
	// Magic C++ stuff that makes input/output faster
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int64_t n, k; cin >> n >> k;
	
	
	// Stores the number of Champernownes divisible by k
	int64_t count = 0;
	
	// Initial Champernowne number. Starts at zero.
	int64_t champ = 0; 
	
	// Loops over all Champernownes (1, 12, 123, 1234, ...)
	for (int64_t i = 1; i <= n; i++) {
		
		// We want to append i to the end of current Champernowne
		
		// Spacer is 1000... with as many zeros as digits in i.
		int64_t spacer = pow(10, countDigits(i));
		
		// Multiplying champ by spacer creates room to add i to the end
		champ = champ * spacer + i;
		
		// But what if champ gets too big to fit in int64_t ???
		// To prevent this we do: champ %= k
		// But won't this mess up the result? No!
		// Thanks to this simple property of the modulo operation:
		// (a + b) % k = ((a % k) + (b % k)) % m
		// (a ⋅ b) % k = ((a % k) * (b % k)) % m
		// See: https://usaco.guide/gold/modular?lang=cpp#introduction
		champ %= k;
		
		
		// If divisible by k, increment count.
		if (champ == 0) {
			count += 1;
		}
	}
	cout << count;
}
