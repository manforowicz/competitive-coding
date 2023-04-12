#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


struct Segment {
	set<int> data;
	
	void init(vector<int> list) {
		sort(list.begin(), list.end());
		data = set<int>(list.begin(), list.end());
	}
	
	int elements_over(int threshold) {
		// off by one?
		return data.end() - data.lower_bound(threshold);
	}
	
	int elements_under(int threshold) {
		// off by one?
		return data.upper_bound(threshold) - data.begin();
	}
};

struct SegmentTree {
	vector<Segment> tree;
	
	void create(vector<int>& data) {
		tree = vector<Segment>(2 * data.size());
		
	}
};



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("in.txt", "r", stdin);
	
	int n, q; cin >> n >> q;
	
	vector<ordered_set<int>> decomp(sqrt(n));
	
	
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		// TODO
	}
}
