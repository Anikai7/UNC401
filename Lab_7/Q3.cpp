#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

using Matrix = vector<vector<int>>;

Matrix buildAdjMatrix(int V, const vector<pair<int, int>>& edges) {
    Matrix adj(V, vector<int>(V, 0));
    for (const auto& [u, v] : edges) {
        adj[u][v] = adj[v][u] = 1;
    }
    return adj;
}

void BFS(const Matrix& adj, int start) {
    int V = adj.size();
    vector<bool> visited(V, false);
    queue<int> q;

    cout << "BFS traversal: ";
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < V; ++i) {
            if (adj[node][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

void DFS(const Matrix& adj, int start) {
    int V = adj.size();
    vector<bool> visited(V, false);

    function<void(int)> dfs = [&](int node) {
        visited[node] = true;
        cout << node << " ";

        for (int i = 0; i < V; ++i) {
            if (adj[node][i] && !visited[i]) {
                dfs(i);
            }
        }
    };

    cout << "DFS traversal: ";
    dfs(start);
    cout << endl;
}

bool hasCycle(const Matrix& adj) {
    int V = adj.size();
    vector<bool> visited(V, false);

    function<bool(int, int)> dfsCycle = [&](int node, int parent) {
        visited[node] = true;

        for (int i = 0; i < V; ++i) {
            if (adj[node][i]) {
                if (!visited[i]) {
                    if (dfsCycle(i, node)) return true;
                } else if (i != parent) {
                    return true;
                }
            }
        }
        return false;
    };

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (dfsCycle(i, -1)) return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<pair<int, int>> edges;
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u, v);
    }

    int start;
    cout << "Enter starting vertex for BFS and DFS: ";
    cin >> start;

    Matrix adj = buildAdjMatrix(V, edges);

    BFS(adj, start);
    DFS(adj, start);

    cout << (hasCycle(adj) ? "Graph contains a cycle." : "Graph does not contain a cycle.") << endl;

    return 0;
}
