#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void topologicalSort(int V, vector<vector<int>>& adj)
{
    vector<int> inDegree(V, 0);
    for (int u = 0; u < V; u++)
        for (int v : adj[u])
            inDegree[v]++;

    queue<int> q;
    for (int i = 0; i < V; i++)
        if (inDegree[i] == 0)
            q.push(i);

    vector<int> topoOrder;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0)
                q.push(v);
        }
    }

    if (topoOrder.size() != V) {
        cout << "The graph is not a Directed Acyclic Graph (DAG), topological order not possible\n";
        return;
    }

    cout << "Topological Ordering: ";
    for (int v : topoOrder)
        cout << v << " ";
    cout << "\n";
}

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);
    cout << "Enter edges (u v) meaning u -> v:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    topologicalSort(V, adj);
    return 0;
}