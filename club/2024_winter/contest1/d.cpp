#include <bits/stdc++.h>
using namespace std;

struct Event {
	int year;
	bool birth;
	
	bool operator < (const Event &other) const {
		if (year == other.year) {
			return (!birth && other.birth);
		}
		return year < other.year;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	
	vector<Event> timeline;
	
	for (int i = 0; i < n; i++) {
		int b, d; cin >> b >> d;
		timeline.push_back(Event{ b, true });
		timeline.push_back(Event{ d, false });
	}
	
	sort(timeline.begin(), timeline.end());
	
	int alive = 0;
	int max_alive = 0;
	int max_year = 0;
	
	for (Event e : timeline) {
		if (e.birth) {
			alive += 1;
			if (alive > max_alive) {
				max_alive = alive;
				max_year = e.year;
			}
		} else {
			alive -= 1;
		}
	}
	
	cout << max_year << ' ' << max_alive << '\n';
}
