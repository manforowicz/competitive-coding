#include <bits/stdc++.h>
using namespace std;

struct Number {
    int original_i;
    int value;
    int answer;
};

bool cmp_i(const Number& a, const Number& b) {
    return a.original_i < b.original_i;
}

bool cmp_value(const Number& a, const Number& b) {
    return a.value < b.value;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    
    for (int test = 0; test < t; test++) {
        int n; cin >> n;
        vector<Number> arr(n);

        for (int i = 0; i < n; i++) {
            arr[i].original_i = i;
            cin >> arr[i].value;
        }

        sort(arr.begin(), arr.end(), cmp_value);

        // the sum of the elements up to the reached one
        int64_t sum = 0;

        // the i just beyond the furthest element reached
        int furthest_i = 0;

        // for every starting element to remove
        for (int i = 0; i < n; i++) {
            while (furthest_i < n) {
                int64_t modifier = 0;
                if (i >= furthest_i) {
                    modifier = arr[i].value;
                }

                if (sum + modifier < arr[furthest_i].value) {
                    break;
                }
                sum += arr[furthest_i].value;
                furthest_i += 1;
            }

            
            arr[i].answer = furthest_i - 1;
        }
        sort(arr.begin(), arr.end(), cmp_i);
        for (int i = 0; i < n; i++) {
            cout << arr[i].answer << ' ';
        }

        cout << '\n';
    }
}