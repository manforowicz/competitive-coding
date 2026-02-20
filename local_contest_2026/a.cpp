#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t t; cin >> t;

    for (int test_case = 0; test_case < t; test_case++) {
        int64_t r; cin >> r;

        int64_t cost = 0;

        int64_t index = 0;
        while (r != 0) {
            int digit = r % 10;

            cost += digit * pow(2, index);

            index++;
            r /= 10;

        }

        cout << cost << endl;
    }
}