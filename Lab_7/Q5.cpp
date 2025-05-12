#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    const int V = 7;
    vector<vector<pair<int, int>>> graph(V);

    auto add = [&](int u, int v, int w) {
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    };

    add(0, 1, 2);
    add(0, 2, 6);
    add(1, 3, 5);
    add(2, 3, 8);
    add(3, 4, 10);
    add(3, 5, 15);
    add(4, 6, 2);
    add(5, 6, 6);

    int source = 1, target = 6;
    vector<int> dist(V, INT_MAX), prev(V, -1);
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (u == target) break;

        for (auto [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[target] == INT_MAX) {
        cout << "No path found.\n";
        return 0;
    }

    vector<int> path;
    for (int at = target; at != -1; at = prev[at])
        path.push_back(at);
    reverse(path.begin(), path.end());

    cout << "Shortest path from " << source << " to " << target << ": ";
    for (int node : path) cout << node << " ";
    cout << "\nTotal distance: " << dist[target] << endl;

    return 0;
}
