#include <bits/stdc++.h>
using namespace std;

// unsolved...


struct Tile {
	int id;
	int price;
	int height;	
};

bool cmp_height(const Tile &a, const Tile &b) {
	if (a.price == b.price) {
		return (a.height < b.height);
	}
	return (a.price < b.price);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	vector<Tile> front(n);
	vector<Tile> back(n);
	for (int i = 0; i < n; i++) {
		cin >> back[i].price;
		back[i].id = i+1;
	}
	for (int i = 0; i < n; i++) {
		cin >> back[i].height;
	}
	for (int i = 0; i < n; i++) {
		cin >> front[i].price;
		front[i].id = i+1;
	}
	for (int i = 0; i < n; i++) {
		cin >> front[i].height;
	}
	
	sort(front.begin(), front.end(), cmp_height);
	sort(back.begin(), back.end(), cmp_height);
	
	
	
	
	for (int i = 0; i < n; i++) {
		if (back[i].height <= front[i].height) {
			cout << "impossible";
			return 0;
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << back[i].id << ' ';
	}
	cout << '\n';
	for (int i = 0; i < n; i++) {
		cout << front[i].id << ' ';
	}
	
}
	
