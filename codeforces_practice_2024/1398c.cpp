#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);

    int t; cin >> t;

    for (int test = 0; test < t; test++) {
        int n; cin >> n;

        int64_t sum = 0;

        // sum to occurences
        unordered_map<int64_t, int64_t> occurences_of_sum;
        occurences_of_sum.insert({0, 1});

        string s; cin >> s;

        for (const char& c : s) {
            int64_t digit = c - 48;

            sum += digit - 1;

            auto it = occurences_of_sum.find(sum);

            if (it == occurences_of_sum.end()) {
                occurences_of_sum.insert({sum, 1});
            } else {
                it->second += 1;
            }
        }

        int64_t ans = 0;

        for (auto it : occurences_of_sum) {
            ans += (it.second * (it.second - 1)) / 2;
        }

        cout << ans << '\n';

    }
}