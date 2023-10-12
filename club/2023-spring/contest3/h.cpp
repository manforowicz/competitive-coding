#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

/*
void dbg(ordered_set s, int k) {
	auto it = s.begin();
	for (int i = 0; i < k; i++) {
		cout << "thing: " << *it << endl;
		it++;
	}
}
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, k; cin >> n >> m >> k;
	
	vector<int64_t> a(n);
	for (int64_t& elem : a) {
		cin >> elem;
	}
	
	ordered_set o_set;
	
	for (int i = 0; i < m; i++) {
		o_set.insert(a[i]);
	}
	
	
	int64_t sum = 0;
	auto it = o_set.begin();
	for (int i = 0; i < k; i++) {
		sum += *it;
		it++;
	}
	cout << sum << ' ';
	
	for (int i = 0; i < n - m; i++) {
		if (o_set.order_of_key(a[i]) < (size_t) k) {
			sum += *o_set.find_by_order(k);
			sum -= a[i];
		}
		o_set.erase(o_set.upper_bound(a[i]));
		o_set.insert(a[i+m]);
		if (o_set.order_of_key(a[i+m]) < (size_t) k) {
			sum -= *o_set.find_by_order(k);
			sum += a[i+m];
			
		}
		//dbg(o_set, k);
		cout << sum << ' ';
	}
		
}
