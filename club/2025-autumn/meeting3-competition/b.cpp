#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> cities(n);

    for (int& city : cities) {
        cin >> city;
    }

    sort(cities.begin(), cities.end());

    
    int total = 0;
    for (int i = 0; i < n/2+1; i++) {
        total += cities[i] / 2;
    }
    for (int i = n / 2 + 1; i < n; i++) {
        total += cities[i];
    }
    

    cout << total << endl;

}