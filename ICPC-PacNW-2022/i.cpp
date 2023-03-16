// I: Counting Satellites
// http://acmicpc-pacnw.org/ProblemSet/Spring2023/pacnw_div1.pdf
// IN PROGRESS

#include <bits/stdc++.h>
using namespace std;

int main() {
	int64_t k; cin >> k;
	
	
	priority_queue<int64_t> factors;
	factors.push(k);
	for (int i = 0; i < 6; i++) {
		int a = sqrt(factors.top());
		int b = factors.top() / a;
		
		factors.pop();
		factors.push(a);
		factors.push(b);
	}
	
	while (!factors.empty()) {
		cout << factors.top() << " ";
		factors.pop();
	}
}
