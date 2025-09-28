program1: 
#include <iostream>
#include <limits> // For INT_MAX (infinity)

using namespace std;

const int INF = numeric_limits<int>::max(); // A large number representing infinity
const int V = 5; // Number of vertices (nodes) in the graph

// Function 1: Find the unvisited vertex with the smallest distance
int minDistance(int dist[], bool visited[]) {
    int min = INF;      // Start with infinity
    int minIndex = -1;  // Index of vertex with minimum distance

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex; // Return index of closest unvisited vertex
}

// Function 2: Print the final shortest distances
void printSolution(int dist[]) {
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << " \t\t " << dist[i] << "\n";
    }
}

// Function 3: Dijkstra’s algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];     // Stores shortest distances
    bool visited[V]; // Tracks visited vertices

    // Step 1: Initialize
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[src] = 0;

    // Step 2: Main loop
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        if (u == -1) break; // No more reachable vertices
        visited[u] = true;

        // Relax neighbors
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Step 3: Print results
    printSolution(dist);
}

// Function 4: Main function
int main() {
    // Example graph as adjacency matrix (0 = no edge)
    int graph[V][V] = {
        // 0   1   2   3   4
        { 0, 10,  0,  0,  5}, // Node 0
        { 0,  0,  1,  0,  2}, // Node 1
        { 0,  0,  0,  4,  0}, // Node 2
        { 7,  0,  6,  0,  0}, // Node 3
        { 0,  3,  9,  2,  0}  // Node 4
    };

    int source = 0; // Start from node 0

    cout << "Dijkstra's Algorithm: Shortest distances from source vertex " 
         << source << ":\n";
    dijkstra(graph, source);

    return 0;
}


program2: 
#include <iostream>
using namespace std;
#define INF 99999
int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    int graph[20][20] = {0}; // adjacency matrix (max 20 vertices)
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) 
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w; // directed graph
        graph[v][u] = w; // remove this line if graph is directed
    }
   int src;
    cout << "Enter source vertex: ";
    cin >> src;
    int dist[20], visited[20];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = -1;
        for (int i = 0; i < V; i++)
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        visited[u] = 1;
        for (int v = 0; v < V; v++) 
        {
            if (graph[u][v] && dist[u] + graph[u][v] < dist[v]) 
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << "\t" << dist[i] << endl;
    }
    return 0;
}
