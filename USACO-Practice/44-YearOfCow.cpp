#include <bits/stdc++.h>
using namespace std;

map<string, int> years = {
	{"Ox", 0},
	{"Tiger", 1},
	{"Rabbit", 2},
	{"Dragon", 3},
	{"Snake", 4},
	{"Horse", 5},
	{"Goat", 6},
	{"Monkey", 7},
	{"Rooster", 8},
	{"Dog", 9},
	{"Pig", 10},
	{"Rat", 11},
};

int main() {
	ios::sync_with_stdio(0);
	//freopen("in.in", "r", stdin);
	
	map<string, int> cows =  { {"Bessie", 0} };
	
	int n; cin >> n;
	
	for (int i=0; i<n; i++) {
		string ignore;
		
		string newCow; cin >> newCow;
		cin >> ignore;
		cin >> ignore;
		string time; cin >> time;
		string zodiac; cin >> zodiac;
		cin >> ignore;
		cin >> ignore;
		string oldCow; cin >> oldCow;
		
		//cout << newCow << " " << time << " " << zodiac << " " << oldCow << endl;
		
		int newTime = years[zodiac];
		
		if (time == "previous" ) {
			//negative
			while (! (newTime < cows[oldCow] and abs(newTime - cows[oldCow]) <= 12)) {
				if (newTime < cows[oldCow]) {
					newTime += 12;
				} else {
					newTime -= 12;
				}
			}
		} else {
			//positive
			while (! (newTime > cows[oldCow] and abs(newTime - cows[oldCow]) <= 12 )) {
				if (newTime <= cows[oldCow]) {
					newTime += 12;
				} else {
					newTime -= 12;
				}
			}
		}
		//cout << newTime << endl;
		
		cows.insert({newCow, newTime});
	}
	
	cout << abs(cows["Elsie"]);
	
	
	return 0;
}
		
	
