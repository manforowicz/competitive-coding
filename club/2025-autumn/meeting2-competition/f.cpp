#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int c, d; cin >> c >> d;


    vector<string> transcript;

    for (int i = c; i <= d; i++) {
        string elem; cin >> elem;
        transcript.push_back(elem);
        // cout << transcript[i-c] << endl;
    }

    // fizz

    int fizz_index = -1;
    int fizz_answer = -1;
    for (int i = c; i <= d; i++) {
        // cout << transcript[i-c] << endl;
        if (transcript[i-c] == "Fizz" || transcript[i-c] == "FizzBuzz") {
            if (fizz_index == -1) {
                fizz_index = i;
                // cout << "HALO" << endl;
            } else {
                fizz_answer = i - fizz_index;
                break;
            }
        }
    }

    if (fizz_index == -1) {
        fizz_answer = d+1;
    } else if (fizz_answer == -1) {
        fizz_answer = fizz_index;
    }


    // buzz
    int buzz_index = -1;
    int buzz_answer = -1;
    for (int i = c; i <= d; i++) {
        if (transcript[i-c] == "Buzz" || transcript[i-c] == "FizzBuzz") {
            if (buzz_index == -1) buzz_index = i;
            else {
                buzz_answer = i - buzz_index;
                break;
            }
        }
    }

    if (buzz_index == -1) {
        buzz_answer = d+1;
    } else if (buzz_answer == -1) {
        buzz_answer = buzz_index;
    }

    cout << fizz_answer << ' ' << buzz_answer << endl;


}
