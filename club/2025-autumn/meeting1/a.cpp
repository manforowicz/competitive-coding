#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    for (int test_case = 0; test_case < t; test_case++) {
        int n; cin >> n;
        int64_t sum = 0;
        
        vector<int64_t> odds;

        for (int i = 0; i < n; i++) {
            int64_t val; cin >> val;

            if (val % 2 == 0) {
                sum += val;
            } else {
                odds.push_back(val);
            }
        }

        // Need to use an odd to get to the evens
        if (odds.size() == 0) {
            cout << 0 << '\n';
            continue;
        }

        sort(odds.begin(), odds.end(), std::greater<int64_t>());

        for (size_t i = 0; i < (odds.size() + 1) / 2; i++) {
            sum += odds[i];
        }

        cout << sum << '\n';
    }


    return 0;
}