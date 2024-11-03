#include <bits/stdc++.h>
using namespace std;
// Program S


// DP ARRAYS
vector<int> cost_to_char;
vector<string> backtrack;

// Updates `index_to_update` with `cost` and `text_to_put` if `cost` is competitive.
void update_dp(int index_to_update, int cost, string text_to_put) {
    if (cost < cost_to_char[index_to_update]) {
        cost_to_char[index_to_update] = cost;
        backtrack[index_to_update] = text_to_put;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("inputs/s1.in", "r", stdin);

    int n, q; cin >> n >> q;

    unordered_map<string, string> translate;

    unordered_map<string, string> translate_other_way;

    for (int i = 0; i < n; i++) {
        string from, to; cin >> from >> to;
        translate.insert({to, from + (char) (65 + i)});
        translate_other_way.insert({from + (char) (65 + i), to});
    }


    for (int query = 0; query < q; query ++) {

        //// PROBLEM

        string target; cin >> target;

        cost_to_char.clear();
        cost_to_char.resize(target.size() + 1, INT_MAX);
        cost_to_char[0] = 0;

        backtrack.clear();
        backtrack.resize(target.size() + 1, string());

        for (int i = 0; i < target.size(); i++) {

            // The case where we simply type a single character
            update_dp(i + 1, cost_to_char[i] + 1, {target[i]});

            for (int j = 1; j <= 24 && i + j <= target.size(); j++) {
                const string substr = target.substr(i, i + j);

                auto it = translate.find(substr);
                if (it != translate.end()) {
                    const string origin = it->second;
                    // cout << "O MY GOD " << origin << '\n';

                    update_dp(i + j, origin.size() + cost_to_char[i], origin);
                }
            }
        }

        // DEBUG STATEMENT ONLY
        // cout << "The cost is: " << cost_to_char[target.size()] << '\n';

        // cout << "BEGIN\n";
        // for (int v = 0; v < backtrack.size(); v++) {
        //     cout << backtrack[v] << endl;
        // }
        // cout << "END" << endl;

        vector<string> solution_segments;

        int i = backtrack.size() - 1;

        // cout << "STILL ALIVE" << endl;

        while (i >= 1) {
            solution_segments.push_back(backtrack[i]);
            if (backtrack[i].size() == 1) {
                i -= 1;
            } else {
                i -= translate_other_way[backtrack[i]].size();
            }
            
            // cout << "The value of i is: " << i << endl;
        }

        // cout << "STILL ALIVE 2" << endl;

        for (int j = (int) solution_segments.size() - 1; j >= 0; j--) {
            // cout << "THe j is: " << j << endl;
            cout << solution_segments[j];
        }

        // cout << "STILL ALIVE OMA" << endl;

        cout << "\n";


        //// END PROBLEM

    }
}