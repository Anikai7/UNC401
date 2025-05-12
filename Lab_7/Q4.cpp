#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

const int INF = 1e9;

int primMST(int V, vector<vector<pair<int, int>>> &adj, int start = 1) {
    vector<bool> visited(V + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});
    int mst_cost = 0;

    while (!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;
        mst_cost += weight;

        for (auto &[v, w] : adj[u]) {
            if (!visited[v]) {
                pq.push({w, v});
            }
        }
    }
    return mst_cost;
}

int find(int x, vector<int> &parent) {
    if (parent[x] != x)
        parent[x] = find(parent[x], parent);
    return parent[x];
}

bool unite(int a, int b, vector<int> &parent, vector<int> &rank) {
    int rootA = find(a, parent);
    int rootB = find(b, parent);
    if (rootA == rootB) return false;

    if (rank[rootA] < rank[rootB])
        swap(rootA, rootB);

    parent[rootB] = rootA;
    if (rank[rootA] == rank[rootB]) rank[rootA]++;
    return true;
}

int kruskalMST(int V, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    vector<int> parent(V + 1), rank(V + 1, 0);
    for (int i = 1; i <= V; ++i)
        parent[i] = i;

    int mst_cost = 0;
    for (auto &[u, v, w] : edges) {
        if (unite(u, v, parent, rank))
            mst_cost += w;
    }
    return mst_cost;
}

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adj(V + 1);
    vector<Edge> edges;

    vector<tuple<int, int, int>> inputEdges = {
        {1, 2, 5}, {1, 3, 2}, {2, 3, 4},
        {2, 5, 1}, {3, 4, 6}, {4, 5, 3}
    };

    for (auto &[u, v, w] : inputEdges) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({u, v, w});
    }

    cout << "Minimum Spanning Tree Cost (Prim's): " << primMST(V, adj, 1) << endl;
    cout << "Minimum Spanning Tree Cost (Kruskal's): " << kruskalMST(V, edges) << endl;

    return 0;
}
