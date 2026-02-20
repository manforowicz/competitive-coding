#include <bits/stdc++.h>
using namespace std;

int problem_id(char problem_letter) {
    return problem_letter - 'A';
}

bool did_they_win(int our_solved, int our_penalty, int their_solved, int their_penalty) {
    if (their_solved > our_solved) {
        return true;
    }
    if (our_solved == their_solved) {
        return (their_penalty < our_penalty);
    }
    return false;
}

struct Problem {
    int solved;
    // Penalities collected before being solved
    int penalties;
    // True iff this problem has been submitted after time
    bool submitted_after_time;
};

bool cmp(const Problem &x, const Problem &y) {
    return x.penalties < y.penalties;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t T; cin >> T;
    for (int64_t testcase = 0; testcase < T; testcase++) {

        // n: # problems
        // a: how many we solved
        // b: our time penalty
        // s: number of other team's submissions
        int64_t n, a, b, s; cin >> n >> a >> b >> s;

        vector<Problem> problems (n);

        // total applicable penalties of the other team
        int64_t other_penalties = 0;
        int64_t other_solved = 0;


        for (int64_t i = 0; i < s; i++) {
            int64_t time;
            char problem_letter;
            string result;

            cin >> time >> problem_letter >> result;

            int prob_i = problem_id(problem_letter);

            if (result == "ac") {
                if (!problems[prob_i].solved) {
                    problems[prob_i].solved = true;
                    problems[prob_i].penalties += time;
                    other_penalties += problems[prob_i].penalties;
                    other_solved += 1;
                }

            } else if (result == "rj") {
                if (!problems[prob_i].solved) {
                    problems[prob_i].penalties += 20;
                }

            } else if (result == "pd") {
                if (!problems[prob_i].solved && !problems[prob_i].submitted_after_time) {
                    problems[prob_i].submitted_after_time = true;
                    problems[prob_i].penalties += time;
                }
                
            } else {
                cout << "PANICKING" << endl;
            }
        }

        
        vector<Problem> unsolved;
        for (Problem p : problems) {
            if (p.submitted_after_time) {
                unsolved.push_back(p);
            }
        }

        sort(unsolved.begin(), unsolved.end(), cmp);

        int extra_count = 0;

        for (size_t i = 0; i < unsolved.size(); i++) {
            if (did_they_win(a, b, other_solved, other_penalties)) {
                break;
            }

            other_solved += 1;
            other_penalties += unsolved[i].penalties;

            extra_count += 1;
        }

        if (did_they_win(a, b, other_solved, other_penalties)) {
            cout << extra_count << endl;
        } else {
            cout << "-1" << endl;
        }

    }
}