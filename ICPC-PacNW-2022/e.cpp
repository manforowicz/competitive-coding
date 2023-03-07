#include <bits/stdc++.h>
using namespace std;

// Color Tubes
// IN PROGRESS

struct Pos {
	int tube, height;
};

struct Color {
	int color, i;
};

// position of the color
vector<vector<Pos>> pos_of_color; // [color][i]

// color of the position
vector<vector<Color>> color_of_pos; // [tube][height]

vector<int> empty_spots;

// moves taken
vector<pair<int, int>> moves;


void debug() {
	cout << "---COLOR OF POS: ----\n";
	for (vector<Color> colors : color_of_pos) {
		for (Color color : colors) {
			cout << "(" << color.color << ", " << color.i << ")";
		}
		cout << endl;
	}
	
	cout << "POS OF COLOR:\n";
	for (vector<Pos> poss : pos_of_color) {
		for (Pos pos : poss) {
			cout << "(" << pos.tube << ", " << pos.height << ")";
		}
		cout << endl;
	}
	
	cout << "EMPTY:\n";
	for (int empty : empty_spots) {
		cout << empty << ' ';
	}
	cout << endl << endl;
}

void add_ball(int color, int tube, int height) {
	if (color == 0) {
		empty_spots.push_back(tube);
		return;
	}
	pos_of_color[color].push_back(Pos{tube, height});
	int color_i = (int) pos_of_color[color].size() - 1;
	color_of_pos[tube].push_back(Color{color, color_i});
}

void move(int from_tube, int to_tube) {
	if (color_of_pos.at(to_tube).size() >= 3 ||
		color_of_pos.at(from_tube).empty()) {
		
		cout << "bzzz" << endl;
		return;
	}

	debug();
	cout << "from: " << from_tube << " to: " << to_tube << endl;
	
	// update color_of_pos
	Color ball = color_of_pos[from_tube].back();
	color_of_pos[from_tube].pop_back();
	color_of_pos[to_tube].push_back(ball);
	
	
	// update pos_of_color
	pos_of_color[ball.color][ball.i] = {to_tube, (int) color_of_pos[to_tube].size() - 1};
	
	// add move to list
	moves.push_back({from_tube+1, to_tube+1});
	

	
	// update empty spots
	auto it = find(empty_spots.begin(), empty_spots.end(), to_tube);
	*it = from_tube;
}

void move_all(int from_tube, int to_tube) {
	move(from_tube, to_tube);
	move(from_tube, to_tube);
	move(from_tube, to_tube);
}

void clear_tube(int tube) {
	while (!color_of_pos[tube].empty()) {
		
		int target = -1;
		for (int spot : empty_spots) {
			if (spot != tube) {
				target = spot;
				break;
			}
		}
		assert(target != -1);
		move(tube, target);
	}
	cout << "TUBE: " << tube << " Cleared" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("in.txt", "r", stdin);
	
	int n; cin >> n;
	
	// position of the color
	pos_of_color.resize(n+1); // [color][i]
	
	// color of the position
	color_of_pos.resize(n+1); // [tube][height]
	
	
	
	// fill vectors
	for (int tube = 0; tube < n+1; tube++) {
		int b, m, t; cin >> b >> m >> t;
		add_ball(b, tube, 0);
		add_ball(m, tube, 1);
		add_ball(t, tube, 2);
	}
	
	
	debug();

	for (int color = 1; color <= n; color++) {
		clear_tube(color);
		int empty_tube = color;
		// bring all balls of color to top layer
		for (Pos pos : pos_of_color[color]) {
			
			if (color_of_pos[pos.tube][0].color == color &&
				color_of_pos[pos.tube][1].color == color &&
				color_of_pos[pos.tube][2].color == color) {
				
				break;
			}
			
			if (pos.height == 0) {
				move_all(pos.tube, empty_tube);
				empty_tube = pos.tube;
			} else if (pos.height == 1) {
				move(0, empty_tube);
				move(pos.tube, empty_tube);
				move(pos.tube, empty_tube);
				move(pos.tube, 0);
				empty_tube = pos.tube;
			} else {
				// Ball already at top
			}
		}
		
		move_all(color, empty_tube);
		empty_tube = color;
		
		for (Pos pos : pos_of_color[color]) {
			move(pos.tube, empty_tube);
		}
	}
	for (pair<int, int> move : moves) {
		cout << move.first << ' ' << move.second << endl;
	}
}
