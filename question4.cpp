#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
    Edge(int _u, int _v, int _weight) : u(_u), v(_v), weight(_weight) {}
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

class UnionFind {
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return false;

        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        }
        else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        }
        else {
            parent[rootY] = rootX;
            ++rank[rootX];
        }
        return true;
    }

private:
    vector<int> parent;
    vector<int> rank;
};

int calculateMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compareEdges);

    UnionFind uf(V);
    int mstWeight = 0;

    for (const auto& edge : edges) {
        if (uf.unite(edge.u, edge.v)) {
            mstWeight += edge.weight;
        }
    }

    return mstWeight;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices (V): ";
    cin >> V;

    cout << "Enter the number of edges (E): ";
    cin >> E;

    vector<Edge> edges;
    cout << "Enter the edges (u v weight):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.emplace_back(u, v, weight);
    }

    int mstWeight = calculateMST(V, edges);

    cout << "Minimum Spanning Tree (MST) Weight: " << mstWeight << endl;

    return 0;
}
