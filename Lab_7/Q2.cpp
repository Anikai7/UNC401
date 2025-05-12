#include <iostream>
#include <queue>
#define MAX 100

using namespace std;

int n;
int adjMatrix[MAX][MAX];
bool visited[MAX];

void resetVisited() {
    for (int i = 0; i < MAX; i++)
        visited[i] = false;
}

void dfs(int node) {
    visited[node] = true;
    for (int i = 1; i <= n; i++) {
        if (adjMatrix[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (adjMatrix[node][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int countComponentsDFS() {
    resetVisited();
    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }

    return count;
}

int countComponentsBFS() {
    resetVisited();
    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bfs(i);
            count++;
        }
    }

    return count;
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adjMatrix[i][j];
        }
    }

    int dfsComponents = countComponentsDFS();
    int bfsComponents = countComponentsBFS();

    cout << "\nConnected Components (DFS): " << dfsComponents << endl;
    cout << "Connected Components (BFS): " << bfsComponents << endl;

    return 0;
}
