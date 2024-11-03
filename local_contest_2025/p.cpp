#include <bits/stdc++.h>
using namespace std;
// Program P

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inputs/p5.txt", "r", stdin);

    int64_t R, C, r0, c0; cin >> R >> C >> r0 >> c0;

    string steps; cin >> steps;

    for (const char c : steps) {
        if (c == 'S') {
            r0 -= 1;
        } else if (c == 'Q') {
            c0 += 1;
        } else if (c == 'R') {
            r0 += 1;
        } else if (c == 'P') {
            c0 -= 1;
        }

        r0 = (r0 + R) % R;
        c0 = (c0 + C) % C;
    }

    cout << r0 << ' ' << c0 << endl;

    
}
