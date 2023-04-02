#include <bits/stdc++.h>
using namespace std;

struct Node {
	int parent = -1;
	int childrenCount = 0;
	int black = 0;
	int white = 0;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("in.txt", "r", stdin);
	
	int tests; cin >> tests;
	for (int t = 0; t < tests; t++) {
		int n; cin >> n;
		vector<Node> nodes(n);
		for (int i = 1; i < n; i++) {
			int parent; cin >> parent; parent -= 1;
			nodes[i].parent = parent;
			nodes[parent].childrenCount += 1;
		}
		
		unordered_set<int> leaves;
		string colors; cin >> colors;
		for (int i = 0; i < n; i++) {
			if (colors[i] == 'B') {
				nodes[i].black = 1;
			} else {
				nodes[i].white = 1;
			}
			if (nodes[i].childrenCount == 0) {
				leaves.insert(i);
			}
		}
		
		int balanced = 0;
		for (int i = 0; i < n-1; i++) {
			auto it = leaves.begin();
			Node child = nodes.at(*it);
			leaves.erase(it);
			Node &parent = nodes.at(child.parent);
			
			parent.childrenCount -= 1;
			parent.black += child.black;
			parent.white += child.white;
			if (parent.childrenCount == 0) {
				leaves.insert(child.parent);
				if (parent.white == parent.black) {
					balanced += 1;
				}
			}
		}
		cout << balanced << '\n';	
	}
}
		
