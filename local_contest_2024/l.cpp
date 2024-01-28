// L

#include <bits/stdc++.h>
using namespace std;


string notes[] = { 
  "A0", "A0#", "B0",
  "C1", "C1#", "D1", "D1#", "E1", "F1", "F1#", "G1", "G1#", "A1", "A1#", "B1",
  "C2", "C2#", "D2", "D2#", "E2", "F2", "F2#", "G2", "G2#", "A2", "A2#", "B2",
  "C3", "C3#", "D3", "D3#", "E3", "F3", "F3#", "G3", "G3#", "A3", "A3#", "B3",
  "C4", "C4#", "D4", "D4#", "E4", "F4", "F4#", "G4", "G4#", "A4", "A4#", "B4",
  "C5", "C5#", "D5", "D5#", "E5", "F5", "F5#", "G5", "G5#", "A5", "A5#", "B5",
  "C6", "C6#", "D6", "D6#", "E6", "F6", "F6#", "G6", "G6#", "A6", "A6#", "B6",
  "C7", "C7#", "D7", "D7#", "E7", "F7", "F7#", "G7", "G7#", "A7", "A7#", "B7",
  "C8" };

int noteToInt(string s) {	
	int i = distance(notes, find(notes, notes + 88, s));
	return i; 
}

int length_of_int_note(int note_i) {
	return notes[note_i].size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// freopen("a.in", "r", stdin);
	
	// cout << noteToInt("A0") << " " << noteToInt("A0#") << " " << noteToInt("C8") << "\n";
	int n; cin >> n;
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		int note = noteToInt(s);
		mp[note]++;
	}
	
	int min_chars = 1e9;
	
	for (int shift = -88; shift <= 88; shift++) {
		int total_length = 0;
		
		for (auto &x : mp) {
			int key = x.first + shift;
			if (key > 87 || key < 0) {
				total_length = 1e9;
				break;
			}
			total_length += length_of_int_note(key) * x.second;
		}
		if (shift != 0) {
			total_length += (shift < 0);
			total_length += (abs(shift) >= 10);
			total_length++;
		
		}

		if (total_length < min_chars) {
			min_chars = total_length;
			// cout << shift << "\n";
		}
	}
	
	cout << min_chars << '\n';
}
