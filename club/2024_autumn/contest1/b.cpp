#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int n; cin >> n;

    vector<char> moves(n);

    int right_h = 0;
    int right_p = 0;
    int right_s = 0;

    for (char& move : moves) {
        cin >> move;

        if (move == 'H') {
            right_h += 1;
        } else if (move == 'P') {
            right_p += 1;
        } else {
            right_s += 1;
        }
    }

    int left_h = 0;
    int left_p = 0;
    int left_s = 0;

    int max_wins = 0;

    for (int i = 0; i < n; i++) {
        if (moves[i] == 'H') {
            left_h += 1;
            right_h -= 1;
        } else if (moves[i] == 'P') {
            left_p += 1;
            right_p -= 1;
        } else {
            left_s += 1;
            right_s -= 1;
        }

        int wins = max(max(left_h, left_p), left_s) + max(max(right_h, right_p), right_s);
        max_wins = max(max_wins, wins);
    }

    cout << max_wins << '\n';
}