#include <bits/stdc++.h>
using namespace std;

int char_to_num(char letter) {
    return letter - 'a';
}

// Returns greatest index that's strictly less than
// the target.
int binary_search(vector<int>& arr, int target) {
    // int min = 0;
    // int max = arr.size() - 1;
    // cout << "arr size: " << arr.size() << endl;

    // while (min < max) {
    //     int mid = min + (max - min) / 2;
    //     cout << "STILL ALIVE 4.1 min" << min << endl;
    //     cout << "STILL ALIVE 4.1 mid" << mid << endl;

    //     cout << "STILL ALIVE 4.1 max" << max << endl;
    //     cout << "arr size: " << arr.size() << endl;


    //     if (arr.at(mid) > target) {
    //         max = mid - 1;
    //     } else if (arr.at(mid) == target) {
    //         return arr.at(mid);
    //     } else {
    //         min = mid;
    //     }
    //     //cout << "STILL ALIVE 4.4" << endl;

    // }
    // //cout << "arr size: " << arr.size() << endl;
    // //cout << min << endl;
    // return min;

    if (arr.size() == 0) {
        return -1;
    }


    int min = 0;
    int max = arr.size() - 1;

    while (min != max) {
        int mid = (min + max + 1) / 2;

        if (arr.at(mid) < target) {
            min = mid;
        } else {
            max = mid - 1;
        }
    }

    if (arr.at(min) >= target) {
        return -1;
    } else {
        return arr.at(min);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;

    cout << "T is : " << T << endl;


    for (int testcase = 0; testcase < T; testcase++) {
        int n, k; cin >> n >> k;
        string s; cin >> s;

        cout << "n is : " << n << endl;

        vector<vector<int64_t>> dp(n+1, vector<int64_t>(26, 1));
        

        //cout << "STILL ALIVE 1" << endl;
        vector<vector<int>> letter_indices(26);
        for (int i = 0; i < n; i++) {
            int letternum = char_to_num(s.at(i));
            letter_indices.at(letternum).push_back(i);
        }

         //cout << "STILL ALIVE 2" << endl;


        for (int i = 0; i < n; i++) {
            //cout << "STILL ALIVE 4.5" << endl;
            for (int letternum = 0; letternum < 26; letternum++) {
                //cout << "STILL ALIVE 4" << endl;

                int64_t sum = 0;
                for (int letternum2 = 0; letternum2 < 26; letternum2++) {
                    //cout << "STILL ALIVE 4.2" << endl;



                    // dp[i][letternum] = // SPECIAL ALGORTIHM
                    int val = binary_search(letter_indices.at(letternum2), i-k-1);
                    if (val == -1) {
                        continue;
                    }
                    // cout << "STILL ALIVE 4.5" << endl;
                    
                    cout << "STILL ALIVE 5" << endl;

                    sum += dp.at(val).at(letternum2);
                    cout << "sum" << sum << endl;
                    sum %= 998244353;
                     //out << "STILL ALIVE 6" << endl;

                }
                dp.at(i).at(letternum) = sum;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                cout << dp.at(i).at(j) << " ";
            }
            cout << endl;
        }

        // sum up
        int64_t final_sum = 0;
        for (int i = 0; i < 26; i++) {
            if (letter_indices.at(i).size() == 0) {
                continue;
            }
            final_sum += dp.at(letter_indices.at(i).at(letter_indices.at(i).size() - 1)).at(i);
        }
        cout << final_sum << endl;
    }
    
}