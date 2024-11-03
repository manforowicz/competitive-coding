#include <bits/stdc++.h>
using namespace std;
// Program T


int64_t str_to_mins(string str) {
    const int64_t MINUTES_IN_HOUR = 60;
    const int64_t MINUTES_IN_DAY = 1440;  // 24 * 60

    int64_t totalMinutes = 0;
    int64_t number = 0;

    for (char ch : str) {
        if (isdigit(ch)) {
            // Build the number
            number = number * 10 + (ch - '0');
        } else {
            // Process the unit
            if (ch == 'd') {
                totalMinutes += number * MINUTES_IN_DAY;
            } else if (ch == 'h') {
                totalMinutes += number * MINUTES_IN_HOUR;
            } else if (ch == 'm') {
                totalMinutes += number;
            }
            // Reset number after processing each unit
            number = 0;
        }
    }
    return totalMinutes;
}

void printWithPeriod(int64_t number) {
    int wholePart = number / 100;  // Get all digits except the last two
    int decimalPart = abs(number % 100);  // Get the last two digits
    std::cout << wholePart << "." << std::setw(2) << std::setfill('0') << decimalPart << '\n';
}

///// HELPERS ABOVE /////


vector<int64_t> cost;
vector<int64_t> duration;

// Find the minimum cost to pay for `time`.
// `maxi` of the max (longest) tier index that can be used
int64_t find_min_cost(int64_t time, int maxi) {
    // No time means zero cost.
    if (time == 0) {
        return 0;
    }

    int i = maxi;

    int64_t lowest_cost = std::numeric_limits<int64_t>::max();;

    while (true) {
        if (i < 0) { return lowest_cost; }

        if (duration[i] < time) {
            break;
        } else {
            lowest_cost = cost[i];
        }

        i -= 1;
    }

    lowest_cost = min(lowest_cost, (time / duration[i]) * cost[i] + find_min_cost(time % duration[i], i));

    return lowest_cost;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inputs/t1.in", "r", stdin);

    int64_t n, q; cin >> n >> q;

    cost.resize(n);
    duration.resize(n);

    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        duration[i] = str_to_mins(str);
        cin >> cost[i];
    }

    // cout << "TEST\n\n";

    // for (int i = 0; i < n; i++) {
    //     cout << duration[i] << ' ' << cost[i] << endl;
    // }

    // cout << "\n\n";


    // Process the queries
    for (int i = 0; i < q; i++) {
        string str; cin >> str;
        int64_t time = str_to_mins(str);
        int64_t min_cost = find_min_cost(time, n - 1);
        cout << '$';
        printWithPeriod(min_cost);
    }
}