#include <bits/stdc++.h>
using namespace std;

// Three Dice
// IN PROGRESS

vector<vector<int>> graph(26);
vector<bool> letters(26);

void print(vector<int> const& v) {
	cout << "[";
	for (auto elem : v) {
		cout << elem << ' ';
	}
	cout << "]" << endl;
}


void finish(vector<vector<int>>& dice) {
	for (vector<int> die : dice) {
		for (int letter : die) {
			cout << (char) (letter + 'a');
		}
		cout << ' ';
	}
	exit(0);
}

void buildDice(vector<vector<int>>& dice, vector<vector<int>>& off_limits, int diceI) {
	
	if (dice[diceI].size() == 6) diceI += 1;
	
	if (diceI == 3) {
		finish(dice);
	}
	
	vector<int> &off_limit = off_limits[diceI];
	vector<int> &die = dice[diceI];
	
	
	int prevLetter = -1;
	if (!die.empty()) {
		prevLetter = die.back();
		for (int letter : graph[prevLetter]) {
			off_limit[letter] += 1;
		}	
	}
	
	for (int letter = prevLetter+1; letter < 26; letter++) {
		if (letters[letter] && off_limit[letter] == 0) {
			//print(dice);
			die.push_back(letter);
			letters[letter] = false;
			
			buildDice(dice, off_limits, diceI);
			
			die.pop_back();
			letters[letter] = true;
		}
	}
	if (!die.empty()) {
		for (int letter : graph[prevLetter]) {
			off_limit[letter] -= 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("in.txt", "r", stdin);
	
	
	int n; cin >> n;
	
	int letterCount = 0;
	for (int i = 0; i < n; i++) {
		string word; cin >> word;
		for (int aI = 0; aI < 3; aI++) {
			int a = (int) word[aI] - 'a';
			
			if (!letters[a]) {
				letterCount += 1;
				letters[a] = true;
			}
			for (int bI = aI + 1; bI < 3; bI++) {
				int b = (int) word[bI] - 'a';
				if (a == b) {
					cout << 0;
					return 0;
				}
				graph[a].push_back(b);
				graph[b].push_back(a);
			}
		}
	}
	
	cout << "'d' DBG...";
	for (auto other : graph['d'-'a']) {
		cout << (char)('a' + other) << ", ";
	}
	cout << endl;
	cout << "'l' DBG...";
	for (auto other : graph['l'-'a']) {
		cout << (char)('a' + other) << ", ";
	}
	cout << endl;
	
	
	for (int i = 0; i < 26; i++) {
		if (letterCount >= 18) break;
		if (!letters[i]) {
			letters[i] = true;
			letterCount += 1;
		}
	}
			
	
	vector<vector<int>> dice(3);
	vector<vector<int>> off_limits(3, vector<int>(26));

	buildDice(dice, off_limits, 0);
	cout << 0;

}
