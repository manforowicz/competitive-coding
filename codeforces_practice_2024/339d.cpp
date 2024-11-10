#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    int64_t n, m; cin >> n >> m;

    int64_t elems = 1;
    for (int i = 0; i < n; i++) {
        elems *= 2;
    }

    vector<vector<int64_t>> tree(n + 1);

    for (int i = 0; i < elems; i++) {
        int64_t val; cin >> val;
        tree[0].push_back(val);
    }

    for (int i = 0; i < n; i++) {

        if (i % 2 == 0) {
            for (size_t j = 0; j < tree[i].size() - 1; j += 2) {
                tree[i + 1].push_back(tree[i][j] | tree[i][j + 1]);
            }
        } else {
            for (size_t j = 0; j < tree[i].size() - 1; j += 2) {
                tree[i + 1].push_back(tree[i][j] ^ tree[i][j + 1]);
            }
        }
    }

    // for (auto sub : tree) {
    //     for (auto elem : sub) {
    //         cout << elem << ' ';
    //     }
    //     cout << endl;
    // }

    // cout << "END\n";

    for (int query = 0; query < m; query++) {
        int64_t p, b; cin >> p >> b;

        p -= 1;

        tree[0].at(p) = b;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                p /= 2;
                tree[i + 1][p] = tree[i].at(p * 2) | tree[i].at(p * 2 + 1);
            } else {
                p /= 2;
                tree[i + 1][p] = tree[i].at(p * 2) ^ tree[i].at(p * 2 + 1);
            }
        }

        cout << tree[n][0] << '\n';
    }
}