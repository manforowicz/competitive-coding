#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	
	vector<int64_t> papers(n);
	for (int64_t &paper : papers) {
		cin >> paper;
	}
	sort(papers.begin(), papers.end());
	
	
	int64_t max_h = 0;
	for (int i = 0; i < n; i++) {
		int64_t num_papers = n - i;
		int64_t citations = papers[i];
		int64_t h = min(num_papers, citations);
		max_h = max(max_h, h);
	}
	cout << max_h;
}
