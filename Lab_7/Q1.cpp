#include <iostream>
#define MAX 100

using namespace std;

int n, m;
int adjMatrix[MAX][MAX];
int adjList[MAX][MAX];
int degree[MAX];

void initialize() {
    for (int i = 0; i < MAX; i++) {
        degree[i] = 0;
        for (int j = 0; j < MAX; j++) {
            adjMatrix[i][j] = 0;
            adjList[i][j] = 0;
        }
    }
}

void addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;

    adjList[u][degree[u]++] = v;
    adjList[v][degree[v]++] = u;
}

void printAdjMatrix() {
    cout << endl << "Adjacency Matrix:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void printAdjList() {
    cout << endl << "Adjacency List:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int j = 0; j < degree[i]; j++) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    initialize();

    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    printAdjMatrix();
    printAdjList();

    return 0;
}
