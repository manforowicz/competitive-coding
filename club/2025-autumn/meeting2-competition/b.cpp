#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w; cin >> h >> w;

    vector<string> map(h);

    for (int i = 0; i < h; i++) {
        string row; cin >> row;
        map[i] = row;
    }

    // even index: on axis
    // odd index: between axes
    vector<vector<double>> costs(h*2+1, vector<double>(w*2+1));

    double circ = 5 * M_PI_2;

    cout << std::fixed << std::setprecision(10);


    for (int i = 0; i < h*2+1; i++) {
        for (int j = 0; j < w*2+1; j++) {

            // setup
            if (i == 0) {
                costs[i][j] = j * 5;
            } else if (j == 0) {
                costs[i][j] = i * 5;
            } else if (i % 2 == 1 && j % 2 == 1) {
                // dot embedded inside city block
                continue;
            } else if (i % 2 == 0 && j % 2 == 0) {
                // on corner
                costs[i][j] = min(costs[i][j-1]+5, costs[i-1][j]+5);
            } else if (i % 2 == 0 && j % 2 == 1) {
                // mid-block on horizontal road
                costs[i][j] = costs[i][j-1] + 5;
                if (map[(i-1)/2][(j-1)/2] == 'O') {
                    costs[i][j] = min(costs[i][j], costs[i-1][j-1]+circ);
                }
            } else if (i % 2 == 1 && j % 2 == 0) {
                // mid-block on vertical road
                costs[i][j] = costs[i-1][j] + 5;
                if (map[(i-1)/2][(j-1)/2] == 'O') {
                    costs[i][j] = min(costs[i][j], costs[i-1][j-1]+circ);
                }
                
            } else {
                cout << "HONO" << endl;
            }

            // double cheapest = 100000000;
            // cheapest = min(cheapest, costs[i-1][j]+10);
            // cheapest = min(cheapest, costs[i][j-1]+10);
            // if (map[i-1][j-1] == 'O') {
            //     cout << "HI" << endl;
            //     cheapest = min(cheapest, costs[i-1][j-1] + M_PI_4*10);
            // }
            // costs[i][j] = cheapest;
        }
    }

    // Print debugging
    // for (int i = 0; i <= h*2; i++) {
    //     for (int j = 0; j <= w*2; j++) {
    //         cout << costs[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << costs[h*2][w*2] << endl;


}
