#include <iostream>
#include <vector>
using namespace std;

void dfsHelper(int node, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& dfsResult) {
    visited[node] = true;
    dfsResult.push_back(node);

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsHelper(neighbor, adj, visited, dfsResult);
        }
    }
}

vector<int> dfsTraversal(int V, const vector<vector<int>>& adj) {
    vector<int> dfsResult;
    vector<bool> visited(V, false);

    dfsHelper(0, adj, visited, dfsResult);

    return dfsResult;
}

void printDFSResult(const vector<int>& dfsResult) {
    for (int node : dfsResult) {
        cout << node << " ";
    }
    cout << endl;
}

int main() {
    int V;
    cout << "Enter the number of vertices (V): ";
    cin >> V;

    vector<vector<int>> adj(V);
    cout << "Enter the adjacency list (-1 to end)" << endl;
    for (int i = 0; i < V; ++i) {
        cout << "Neighbors of vertex " << i << ": ";
        int neighbor;
        while (cin >> neighbor && neighbor != -1) {
            adj[i].push_back(neighbor);
        }
    }

    vector<int> dfsResult = dfsTraversal(V, adj);

    cout << "DFS Traversal Result:" << endl;
    printDFSResult(dfsResult);

    return 0;
}
