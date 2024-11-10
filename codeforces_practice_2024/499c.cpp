#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    int n; cin >> n;

    vector<int64_t> arr(n);

    int64_t target_sum = 0;

    for (int64_t& elem : arr) {
        cin >> elem;
        target_sum += elem;
    }

    if (target_sum % 3 != 0) {
        cout << 0 << '\n';
        return 0;
    }
    
    target_sum /= 3;

    vector<int> possible_i(n);

    int64_t segment_sum = 0;

    for (int i = 0; i < n - 1; i++) {
        
        segment_sum += arr[i];
        if (segment_sum == target_sum) {
            possible_i[i] += 1;
        }

        possible_i[i + 1] = possible_i[i];
    }

    segment_sum = 0;

    int64_t ans = 0;

    for (int j = n - 1; j > 1; j--) {
        segment_sum += arr[j];

        if (segment_sum == target_sum) {
            ans += possible_i[j - 2];
        }
        
    }

    cout << ans << '\n';
}