#include <bits/stdc++.h>
using namespace std;

int num_chip_combos(vector<int>& chip_counts, int max_allowance, int index) {
    if (max_allowance == 0 || index >= chip_counts.size()) {
        return 1;
    }

    int combos = 0;


    for (int i = 0; i < min(max_allowance, chip_counts[index]); i++) {
        combos += num_chip_combos(chip_counts, max_allowance-i, index+1)
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, q; cin >> n >> q;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> max_use(n-1);
    for (int i = 0; i < n-1; i++) {
        max_use[i] = (coins[i+1] - 1) / coins[i];
    }

    for ()

    cout << num_chip_combos(chip_counts, )




    
}