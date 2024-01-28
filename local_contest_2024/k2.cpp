// K

#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x;
	int y;
	int cost;
};

void bfs(vector<string>& board, int y, int x, int (&dist)[26][26]) {
	if (board[y][x] == '0') return;
	queue<Point> q;
	
	int i = board[y][x] - 'A';
	
	bool visited[26] = { false };
	
	q.push({x, y, 1});
	
	while (!q.empty()) {
		Point p = q.front();
		q.pop();
		
		// cout << p.x << " " << p.y << " " << p.cost << "\n";
		
		int letter = board[p.y][p.x] - 'A';
		
		if (visited[letter]) {
			continue;
		}
		visited[letter] = true;
		
		dist[i][letter] = p.cost;
		
		int new_x;
		int new_y;
		
		// down
		new_x = p.x;
		new_y = p.y;
		do {
			new_y += 1;
			new_y += board.size();
			new_y %= board.size();
		} while (board[new_y][new_x] == '0');
		
		q.push({new_x, new_y, p.cost + 1});
		
		// up
		new_x = p.x;
		new_y = p.y;
		do {
			new_y -= 1;
			new_y += board.size();
			new_y %= board.size();
		} while (board[new_y][new_x] == '0');
		q.push({new_x, new_y, p.cost + 1});
		
		// right
		new_x = p.x;
		new_y = p.y;
		do {
			new_x += 1;
			new_x %= board[0].size();
		} while (board[new_y][new_x] == '0');
		q.push({new_x, new_y, p.cost + 1});
		
		// left
		new_x = p.x;
		new_y = p.y;
		do {
			new_x -= 1;
			new_x += board[0].size();
			new_x %= board[0].size();
		} while (board[new_y][new_x] == '0');
		q.push({new_x, new_y, p.cost + 1});
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// freopen("a.in", "r", stdin);
	
	vector<string> board = {
		"0000000",
		"00AB000",
		"00CDE00",
		"0FGHIJ0",
		"0KLMNO0",
		"0PQRST0",
		"00UVW00",
		"00XY000",
		"000Z000",
		"0000000"
	};
	
	
	int dist[26][26];
	memset(dist, 0, sizeof(int) * 26 * 26);
	
	for (int y = 0; y < board.size(); y++) {
		for (int x = 0; x < board[0].size(); x++) {
			bfs(board, y, x, dist);
		}
	}
	
	string s; cin >> s;
	s = "A" + s;
	int cost = 0;
	for (int i = 1; i < s.size(); i++) {
		int k1 = s[i - 1] - 'A';
		int k2 = s[i] - 'A';
		cost += dist[k1][k2];
	} 
	
	cout << cost << "\n";
}
