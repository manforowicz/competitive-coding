#include <bits/stdc++.h>
using namespace std;


int64_t count_squares(double radius) {
    int64_t i = 0;

    int64_t num_squares = 0;

    for (int64_t x = 1; x < radius; x++) {
        double y = sqrt(radius*radius - x*x);
        num_squares += 4 * ((int64_t) y);
    }

    return num_squares;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t s; cin >> s;

    double min = 0;
    double max = sqrt((double) s);

    cout << std::fixed << std::setprecision(10);

    while (max - min > 0.00000000001) {
        double mid = (max + min) / 2;

        int64_t squares = count_squares(mid);
        // cout << "squares: " << mid << endl;

        if (squares <= s) {
            min = mid;
        } else {
            max = mid;
        }
    }
    
    cout << max << endl;

}
