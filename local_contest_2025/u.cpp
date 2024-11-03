#include <bits/stdc++.h>
using namespace std;
// Program G

void dfs(int i, set<int> &visited, vector<int> &factors, vector<int> &v, int cnt) {
    if (visited.count(i)) {
        if (cnt != 0) factors.push_back(cnt);
        return;
    }

    visited.insert(i);
    cnt++;
    dfs(v[i], visited, factors, v, cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inputs/u3.in", "r", stdin);

    int n; cin >> n;
    vector<int> v(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i + 1];
    }

    vector<int> arr;
    set<int> visited;
    for (int i = 1; i <= n; i++) {
        dfs(i, visited, arr, v, 0);
    }

    long long ans = arr[0];

    // ans contains LCM of arr[0], ..arr[i]
    // after i'th iteration,
    for (unsigned int i = 1; i < arr.size(); i++)
        ans = (((arr[i] * ans)) /
                (gcd(arr[i], ans)));

    cout << ans - 1 << "\n";
}