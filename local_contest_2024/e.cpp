// E

#include <bits/stdc++.h>
using namespace std;

struct Person {
	int children[26];
	int letter;
};

void recurse(int i, vector<Person>& people) {
	cout << i << ' ';
	
	for (int child : people[i].children) {
		if (child == -1) {
			continue;
		}
		
		recurse(child, people);
	}
}
	

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// freopen("a.in", "r", stdin);
	
	int n; cin >> n;
	
	vector<Person> people;

	
	Person p;
	fill(begin(p.children), end(p.children), -1);
	
	
	people.push_back(p);
	
	for (int i = 1; i <= n; i++) {
		char c;
		int parent;
		cin >> c >> parent;
		
		int letter = c - 'A';
		
		cout << "DEBUG: " << letter << endl;
		
		Person p;
		p.letter = letter;
		fill(begin(p.children), end(p.children), -1);
		
		people[parent].children[letter] = i;
		
		people.push_back(p);
	}
	
	// DEBUG
	
	for (int i = 1; i <= n; i++) {
		cout << "PERSON" << endl;
		cout << i << ": " << char('A' + people[i].letter) << endl;
		
		for (int elem : people[i].children) {
			cout << elem << " ";
		}
		cout << endl;
		
	}
	
	recurse(1, people);
}
