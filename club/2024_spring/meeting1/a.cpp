#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;

    vector<int64_t> h(n);

    for (int64_t& element : h) {
        cin >> element;
    }

    sort(h.begin(), h.end());

    int64_t total = min(k, n);

    for (int i = 0; i < n - k; i++) {
        total += h[i];
    }

    cout << total << '\n';

}