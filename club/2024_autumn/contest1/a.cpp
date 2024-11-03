#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int n, q; cin >> n >> q;

    vector<int> prefix1(n + 1);
    vector<int> prefix2(n + 1);
    vector<int> prefix3(n + 1);

    for (int i = 0; i < n; i++) {
        prefix1[i + 1] = prefix1[i];
        prefix2[i + 1] = prefix2[i];
        prefix3[i + 1] = prefix3[i];

        int breed; cin >> breed;

        if (breed == 1) {
            prefix1[i + 1] += 1;
        } else if (breed == 2) {
            prefix2[i + 1] += 1;
        } else {
            prefix3[i + 1] += 1;
        }
        
    }

    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;

        int count1 = prefix1[r] - prefix1[l - 1];
        int count2 = prefix2[r] - prefix2[l - 1];
        int count3 = prefix3[r] - prefix3[l - 1];

        cout << count1 << ' ' << count2 << ' ' << count3 << '\n';
    }
}
