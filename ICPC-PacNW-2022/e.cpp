#include <bits/stdc++.h>
using namespace std;

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


void add_ball(int color, int tube, int height) {
	if (color == 0) {
		return;
	}
	pos_of_color[color].push_back(Pos{tube, height});
	int color_i = (int) pos_of_color.size() - 1;
	color_of_pos[tube].push_back(Color{color, color_i});
}

void move(int from_tube, int to_tube) {
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	
	// position of the color
	vector<vector<Pos>> pos_of_color(n+1); // [color][i]
	
	// color of the position
	vector<vector<Color>> color_of_pos(n+2); // [tube][height]
	
	
	// fill vectors
	for (int tube = 0; tube < n+1; tube++) {
		int b, m, t; cin >> b >> m >> t;
		add_ball(b, tube, 0);
		add_ball(m, tube, 1);
		add_ball(t, tube, 2);
	}
	
	// empty first tube
	for (int color_of_pos[0].size()-1; i >= 0; i--) {
		
		// loop over all tubes, checking for empty
		for (size_t tube = 0; tube < color_of_pos.size(); tube++) {
			
			// check if tube is empty
			if (find(color_of_pos[tube].begin(), color_of_pos[tube].end(), 0) != color_of_pos[tube].end())  {
			}
		}
	}
				
		
	
	for (int color = 1; color <= n; color++) {
		
		
	}
}
