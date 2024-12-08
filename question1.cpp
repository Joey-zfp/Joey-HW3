#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> createAdjList(int V, vector<pair<int, int>>& edges) {
    vector<vector<int>> adjList(V);

    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return adjList;
}

void printAdjList(const vector<vector<int>>& adjList) {
    for (int i = 0; i < adjList.size(); ++i) {
        cout << i << ": ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices (V): ";
    cin >> V;

    cout << "Enter the number of edges (E): ";
    cin >> E;

    vector<pair<int, int>> edges;
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u, v);
    }

    vector<vector<int>> adjList = createAdjList(V, edges);

    cout << "Adjacency List:" << endl;
    printAdjList(adjList);

    return 0;
}
