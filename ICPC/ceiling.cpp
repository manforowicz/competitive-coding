#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int k; cin >> k;
    
    vector<vector<bool>> trees;
    int different_trees = 0;
    
    for (int round = 0; round < n; round++) {
		vector<int> tree(pow(2, k+2));
		vector<bool> tree_positions(pow(2, k+2));
		
		for (int i = 0; i < k; i++) {
			int insertion; cin >> insertion;
			int index = 0;
			while (tree[index] != 0) {
				if (insertion < tree[index]) {
					index = 2 * index + 1;
				} else {
					index = 2 * index + 2;
				}
			}
			tree[index] = insertion;
			tree_positions[index] = true;
		}
		
		
		if (find(trees.begin(), trees.end(), tree_positions) == trees.end()) {
			trees.push_back(tree_positions);
			different_trees++;
		}
	}
	cout << different_trees;
}
