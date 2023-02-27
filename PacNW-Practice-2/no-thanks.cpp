#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	
	vector<int> cards(n);
	
	for (int &card : cards) {
		cin >> card;
	}
	sort(cards.begin(), cards.end());
	
	int64_t sum = cards[0];
	
	for (int i = 1; i < n; i++) {
		if (cards[i] - cards[i-1] != 1) {
			sum += cards[i];
		}
	}
	cout << sum;
}
