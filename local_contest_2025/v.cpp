#include <bits/stdc++.h>
using namespace std;
// Program H

unordered_map<string, char> mp = {
    {"1010110", '0'},
    {"11010110", '1'},
    {"10010110", '2'},
    {"11001010", '3'},
    {"10110110", '4'},
    {"11011010", '5'},
    {"10011010", '6'},
    {"10100110", '7'},
    {"11010010", '8'},
    {"1101010", '9'},
    {"1011010", '-'},
    {"10110010", 's'}
};

void testcase(string s) {
    stringstream ss;
    int sCount = 0;
    for (unsigned int i = 0; i < s.size();) {
        // cout << ss.str() << "\n";

        string s7 = s.substr(i, 8);
        if (mp.count(s7)) {
            ss << mp[s7];
            if (mp[s7] == 's') sCount++;
            // if (i + 7 < s.size() && s[i + 7] != '0') {
            //     cout << "INVALID\n"; return;
            // }
            i += 8;
            continue;
        }

        string s6 = s.substr(i, 7);
        if (mp.count(s6)) {
            ss << mp[s6];
            if (mp[s6] == 's') sCount++;
            // if (i + 6 < s.size() && s[i + 6] != '0') {
            //     cout << "INVALID\n"; return;
            // }
            i += 7;
            continue;
        } 

        cout << "INVALID\n"; return;
    }
    s = ss.str();
    // cout << s << "\n";
    if (s[0] != 's' || s[s.size() - 1] != 's' || s.size() <= 2 || sCount != 2) {
        cout << "INVALID\n"; return;
    }

    cout << s.substr(1, s.size() - 2) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inputs/v1.in", "r", stdin);

    int testcases; cin >> testcases;
    for (int i = 0; i < testcases; i++) {
        int size; cin >> size;
        stringstream levels;
        for (int j = 0; j < size; j++) {
            int val; cin >> val;
            levels << (val > 127 ? "0" : "1");
        }
        testcase(levels.str() + "0");
    }
    return EXIT_SUCCESS;
}

