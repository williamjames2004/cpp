#include <iostream>
#include <vector>
using namespace std;

const int INF = 999;

int main()
{
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> g(V, vector<int>(V));
    cout << "Enter the adjacency matrix:\n";
    for (auto &row : g)
        for (int &w : row)
            cin >> w;

    vector<int> key(V, INF), parent(V, -1);
    vector<bool> inMST(V, false);
    key[0] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        int u = -1;

        // Pick vertex with minimum key value not yet in MST
        for (int j = 0; j < V; j++)
            if (!inMST[j] && (u == -1 || key[j] < key[u]))
                u = j;

        inMST[u] = true;

        // Update key and parent for adjacent vertices
        for (int v = 0; v < V; v++)
        {
            if (g[u][v] && !inMST[v] && g[u][v] < key[v])
            {
                key[v] = g[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "\nMinimum Spanning Tree:\n";
    int total = 0;
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << "  Weight: " << g[i][parent[i]] << "\n";
        total += g[i][parent[i]];
    }

    cout << "Total weight: " << total << "\n";
    return 0;
}