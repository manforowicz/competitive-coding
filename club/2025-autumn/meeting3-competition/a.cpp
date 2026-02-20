#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int s, n; cin >> s >> n;

    vector<int> taken(n);

    for (int& seat : taken) {
        int val; cin >> val;
        seat = val;
    }

    sort(taken.begin(), taken.end());


    int answer = 0;

    int last_seen_ago = 0;

    for (int i = 0; i < n-1; i++) {
        answer += (taken[i+1] - taken[i]-2) / 2;
    }

    answer += (taken[0] + s - taken[n-1]-2) / 2;

    cout << answer << endl;

}