#include <bits/stdc++.h>
using namespace std;
// Program N

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inputs/n3.in", "r", stdin);

    int64_t N; cin >> N;
    vector<string> solutions;

    // int64_t a = 1e9;
    // int64_t b = pow(N, 1./3);
    // int64_t exp;
    // while (b > 0) {
    //     exp = (6 * N) / (b * (b + 1) * (2 * b + 1));
    //     a = sqrt(exp);
    //     if ((6 * N) % (b * (b + 1) * (2 * b + 1)) == 0 && a * a == exp) {
    //         stringstream ss;
    //         ss << a << " " << b;
    //         solutions.push_back(ss.str());
    //     }
    //     // a++;
    //     // if ((6 * N) % (b * (b + 1) * (2 * b + 1)) == 0 && a * a == exp) {
    //     //     stringstream ss;
    //     //     ss << a << " " << b;
    //     //     solutions.push_back(ss.str());
    //     // }
    //     b -= 1;
    // }

    long long sum = 0;
    for (long long b = 1; ; b++) {
        if (N - b * b < sum) {
            break;
        }
        // cout << b << " " <<sum << "\n";
        sum += b * b;
        if (N % sum != 0) continue;
        long long rem = N / sum;
        long long a = sqrt(rem);
        if (rem % a == 0 && a == rem / a) {
            stringstream ss;
            ss <<  a << " " << b;
            solutions.push_back(ss.str());
        } else if (rem % (a + 1) == 0 && (a + 1) == rem / (a + 1)) {
            stringstream ss;
            ss <<  a << " " << b;
            solutions.push_back(ss.str());
        }
    }

    if (solutions.size() > 0) {
        sort(solutions.begin(), solutions.end());
        cout << "YES" << endl;
        cout << solutions[0] << endl;
    } else {
        cout << "NO" << endl;
    }
    return EXIT_SUCCESS;
}