#include <bits/stdc++.h>
using namespace std;
// Program I

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("inputs/w1.in", "r", stdin);

    int x, y; cin >> x >> y;
    vector<vector<long long>> v(x, vector<long long>(y, 0));
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> v[i][j];
        }
    }

    long long mn = 1e12;

    for (int i = 0; i < x - 4; i++) {
        for (int j = 0; j < y - 1; j++) {
            long long sum = 0;
            for (int ii = 0; ii < 5; ii++) {
                int jj = j;
                if (ii & 1) jj++;
                if (v[ii][jj] == -1) {
                    sum = -1;
                    break;
                }
                sum += v[ii][jj];
            }
            if (sum == -1) continue;
            if (sum < mn) {
                mn = sum;
            }
        }
    }

    if (mn == 1e12) {
        cout << "-1\n";
    } else {
        cout << mn << "\n";
    }
}