#include <bits/stdc++.h>
using namespace std;

int fact(int num) {
	for (int i = num-1; i > 1; i--) {
		num *= i;
	}
	return num;
}

struct Combination {
	int perms; // number of permutations
	double prob; // probability per permutation
	double exp_length;
	
	bool operator < (const Combination &other) const {
		return prob < other.prob;
	}
};

int main() {
	int n; cin >> n;
	int ps, pc, pr, pf; cin >> ps >> pc >> pr >> pf;
	
	priority_queue<Combination> combinations;
	
	for (int s = 0; s < n; s++) {
		for (int c = 0; s < n-s; c++) {
			for (int r = 0; s < n-s-c; r++) {
				for (int f = 0; s < n-s-c-r; f++) {
					int perms = fact(n) / fact(s) / fact(c) / fact(r) / fact(f);
					double prob = s*ps + c*pc + r*pr + f*pf;
					combinations.push({perms, prob, 0});	
				}
			}
		}
	}
	
	while (combinations.size() != 1) {
		Combination c = combinations.top();
		combinations.pop();
		combinations.push({c.perms/2, c.prob/2*2*2, c.prob*c.perms*c.exp_length});
		
		if (c.perms % 2 == 1) {
			Combination next = combinations.top();
			combinations.pop();
			combinations.push({next.perms-1, next.prob, next.exp_length});
			
			combinations.push({1, c.prob + next.prob, c.prob*c.exp_length});
		}
	}
					
	int64_t hi[n][n][n][n];
}
