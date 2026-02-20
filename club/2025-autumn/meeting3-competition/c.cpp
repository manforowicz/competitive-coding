#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> a(n);
    for (int& elem : a) {
        cin >> elem;
    }

    vector<int> b(n);
    for (int& elem : b) {
        cin >> elem;
    }

    

    unordered_multiset<int> unmatched_a;
    unordered_multiset<int> unmatched_b;


    for (int i = 0; i < n; i++) {
        unmatched_a.insert(a[i]);
        unmatched_b.insert(b[i]);

        if (find(unmatched_b.begin(), unmatched_b.end(), a[i]) != unmatched_b.end()) {
            unmatched_a.erase(a[i]);
            unmatched_b.erase(a[i]);
        }
        if (find(unmatched_a.begin(), unmatched_a.end(), b[i]) != unmatched_a.end()) {
            unmatched_a.erase(a[i]);
            unmatched_b.erase(a[i]);
        }

        cout << unmatched_a.size() << ' ' << unmatched_b.size() << endl;

        if (unmatched_a.size() != unmatched_b.size()) {
            cout << "OOPSIE\n";
        }

        if (unmatched_a.empty() && unmatched_b.empty()) {
            cout << "# ";
        }
        // cout << b[i] << ' ';
    }
    cout << endl;

}