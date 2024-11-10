#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    string s; cin >> s;

    int64_t b_per_burger = 0;
    int64_t s_per_burger = 0;
    int64_t c_per_burger = 0;

    for (const char& c : s) {
        if (c == 'B') {
            b_per_burger += 1;
        } else if (c == 'S') {
            s_per_burger += 1;
        } else if (c == 'C') {
            c_per_burger += 1;
        }
    }

    int64_t nb, ns, nc; cin >> nb >> ns >> nc;
    int64_t pb, ps, pc; cin >> pb >> ps >> pc;
    int64_t rubles; cin >> rubles;

    int64_t maxi = nb + ns + nc + rubles;
    int64_t mini = 0;

    while (mini != maxi) {
        int64_t mid = (mini + maxi + 1) / 2;

        int64_t cost_b = pb * max((mid * b_per_burger) - nb, (int64_t) 0);
        int64_t cost_s = ps * max((mid * s_per_burger) - ns, (int64_t) 0);
        int64_t cost_c = pc * max((mid * c_per_burger) - nc, (int64_t) 0);

        if (cost_b + cost_s + cost_c > rubles) {
            maxi = mid - 1;
        } else {
            mini = mid;
        }
    }
    
    cout << mini << '\n';

}