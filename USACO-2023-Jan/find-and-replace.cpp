#include <bits/stdc++.h>
using namespace std;

int char_to_num(char c) {
	if (c - 'A' < 26) {
		return c - 'A';
	} else {
		return c - 'a' + 26;
	}
}

vector<vector<int>> graph;
vector<bool> explored;

bool is_cycle(int curr) {

	bool cycle = (graph[curr].size() == 2);
	if (explored[curr]) {
		return cycle;
	}
	explored[curr] = true;
	for (int next : graph[curr]) {
		cycle = (cycle && is_cycle(next));
	}
	return cycle;
}


int solve() {
	
	graph = vector<vector<int>>(52, vector<int>(0));
	explored = vector<bool>(52, false);
	
	vector<int> translations(52, -1);
	vector<bool> final_letters(52, false);
		
	string origin, target; cin >> origin >> target;
	
	if (origin == target) {
		return 0;
	}
	
	int final_letter_count = 0;
	int diffs_count = 0;
	
	for (size_t i = 0; i < origin.size(); i++) {
		int from = char_to_num(origin[i]);
		int to = char_to_num(target[i]);
		
		if (!final_letters[to]) {
			final_letters[to] = true;
			final_letter_count++;
		}
		
		if (translations[from] == -1) {
			translations[from] = to;
			if (to != from) {
				graph[from].push_back(to);
				graph[to].push_back(from);
				diffs_count++;
			}
		} else if (translations[from] != to) {
			return -1;
		}
	}
	if (final_letter_count == 52) {
		return -1;
	}
	for (int i = 0; i < 52; i++) {
		if (!explored[i]) {
			diffs_count += is_cycle(i);
		}
	}
	return diffs_count;
}


int main() {
	int t; cin >> t;
	
	for (int test = 0; test < t; test++) {
		cout << solve() << '\n';
		
	}
}
