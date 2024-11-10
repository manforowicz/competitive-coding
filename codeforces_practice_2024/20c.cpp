#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    int n, m; cin >> n >> m;

    vector<vector<pair<int64_t, int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }

    vector<int> backtrack(n + 1);

    vector<int64_t> dist(n + 1, INT64_MAX);

    using T = pair<int64_t, int>;
    priority_queue<T, vector<T>, greater<T>> queue;

    queue.push({0, n});
    dist[n] = 0;

    while (!queue.empty()) {
        const auto [cdist, node] = queue.top();
        queue.pop();
        if (cdist != dist[node]) continue;

        for (const pair<int64_t, int> &i : adj[node]) {
            if (cdist + i.first < dist[i.second]) {
                dist[i.second] = cdist + i.first;
                backtrack[i.second] = node;
                queue.push({dist[i.second], i.second});
            }
        }
    }

    if (backtrack[1] == 0) {
        cout << "-1\n";
    } else {
        int i = 1;
        while (i != n) {
            cout << i << ' ';
            i = backtrack[i];
        }
        cout << i << '\n';
    }


}