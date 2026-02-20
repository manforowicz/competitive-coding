#include <bits/stdc++.h>
using namespace std;

struct Event {
    int64_t time;
    int64_t node_i;
    // Refresher - drop to zero
    // Otherwise, decrement by one
    bool refresher;
};

bool operator<(const Event &x, const Event &y) {
    return x.time > y.time;
}

struct Edge {
    int64_t dest_i;
    int64_t w;
};

struct Node {
    vector<Edge> neighbors;
    int64_t remaning_left;
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // n: num problems (nodes)
    // m: number of edges
    // k: number of refreshers

    int64_t n, m, k; cin >> n >> m >> k;

    priority_queue<Event> queue;
    vector<Node> nodes(n);
    unordered_set<int64_t> node_i_finished;

    // Get the thresholds of nodes
    for (int64_t i =0; i < n; i++) {
        int64_t ai; cin >> ai;
        nodes[i].remaning_left = ai;
        
        if (ai == 0) {
            Event event;
            event.time = 0;
            event.node_i = i;
            event.refresher = true;
            queue.push(event);
        }
    }

    // Getting the list of refereshers
    for (int64_t i=0; i < k; i++) {
        int64_t time, num_nodes; cin >> time >> num_nodes;

        for (int64_t j=0; j < num_nodes; j++) {
            int64_t node_i; cin >> node_i;
            node_i--;
            Event event;
            event.node_i = node_i;
            event.time = time;
            event.refresher = true;
            queue.push(event);
        }
    }

    // Getting the graph edges
    for (int64_t i=0; i < m; i++) {
        int64_t u, v, w; cin >> u >> v >> w;
        u--; v--;

        Edge edge;
        edge.dest_i = v;
        edge.w = w;
        nodes[u].neighbors.push_back(edge);
    }

    
    vector<int64_t> time_cleared(n, -1);


    while (!queue.empty()) {
        Event event = queue.top();
        queue.pop();

        // Ignore this node if it was already cleared
        if (time_cleared[event.node_i] != -1) {
            continue;
        }

        if (event.refresher) {
            nodes[event.node_i].remaning_left = 0;
        } else {
            nodes[event.node_i].remaning_left -= 1;
        }

        if (nodes[event.node_i].remaning_left <= 0) {
            node_i_finished.insert(event.node_i);
            time_cleared[event.node_i] = event.time;

            nodes[event.node_i].remaning_left = 0;
            for (Edge edge : nodes[event.node_i].neighbors) {
                Event new_event;
                new_event.node_i = edge.dest_i;
                new_event.time = event.time + edge.w;
                // cout << "WEIGHT: " << edge.w << endl;
                new_event.refresher = false;
                queue.push(new_event);
            }
        }

        // cout << "TIME: " << event.time << endl;;
        // cout << "FOO: " << node_i_finished.size() << endl;
        // cout << "BOO: " << queue.size() << endl;

        if (node_i_finished.size() == (size_t) n) {
            break;
        }
    }

    // Print64_t remaning energies
    // cout << "ENERGIES:" << endl;
    // for (int64_t i = 0; i < n; i++) {
    //     cout << nodes[i].remaning_left << ' ';
    // }
    // cout << endl << endl;
    

    // Iterate through all the nodes
    for (int64_t i = 0; i < n; i++) {
        cout << time_cleared[i] << ' ';
    }
    cout << endl;
}
