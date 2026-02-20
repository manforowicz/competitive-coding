#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    int mini, maxi;
    cin >> maxi;
    mini = maxi;

    for (int i = 0; i < n - 1; i++) {
        int val; cin >> val;
        maxi = max(maxi, val);
        mini = min(mini, val);
    }

    cout << max(0, mini - maxi / 2) << endl;

    return 0;
}