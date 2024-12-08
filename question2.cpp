#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsTraversal(const vector<vector<int>>& adj) {
    vector<int> bfsResult;
    vector<bool> visited(adj.size(), false);
    queue<int> q;

    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfsResult.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return bfsResult;
}

void printBFSResult(const vector<int>& bfsResult) {
    for (int node : bfsResult) {
        cout << node << " ";
    }
    cout << endl;
}

int main() {
    int V;
    cout << "Enter the number of vertices (V): ";
    cin >> V;

    vector<vector<int>> adj(V);
    cout << "Enter the adjacency list" << endl;
    for (int i = 0; i < V; ++i) {
        cout << "Enter neighbors of vertex " << i << " (end with -1): ";
        int neighbor;
        while (cin >> neighbor && neighbor != -1) {
            adj[i].push_back(neighbor);
        }
    }

    vector<int> bfsResult = bfsTraversal(adj);

    cout << "BFS Traversal Result:" << endl;
    printBFSResult(bfsResult);

    return 0;
}
