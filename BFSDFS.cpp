BFS:
program: 
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
void BFS(int startnode, vector<vector<int>>&adj, vector<bool>&visited)
{
    queue<int> q;
    visited[startnode] = true;
    q.push(startnode);
    
    cout<<"BFS Traversal";
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        //Visit all the adjacancy node
        for(int neighbor: adj[node])
        {
            if(!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout<<endl;
}

int main()
{
    int nodes, edges;
    cout<<"Enter the number of nodes and edges; ";
    cin>>nodes>>edges;
    vector<vector<int>>adj(nodes+1);
    vector<bool>visited(nodes+1,false);
    
    cout<<"Enter the edges (u v): ";
    for(int i=0;i<edges;++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int startnode;
    cout<<"Enter the Starting node: ";
    cin>>startnode;
    
    BFS(startnode, adj, visited);
    
    return 0;
}

output: 
Enter the number of nodes and edges; 5 4
Enter the edges (u v): 1 2
1 3
2 4
3 5
Enter the Starting node: 1
1 2 3 4 5 


=== Code Execution Successful ===

DFS: 
program: 
#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<vector<int>>&adj, vector<bool>&visited)
{
    visited[node]=true;
    cout<<node<<" ";
    for(int neighbor: adj[node])
    {
        if(!visited[neighbor])
        {
            DFS(neighbor, adj, visited);
        }
    }
}
int main()
{
    int nodes, edges;
    cout<<"Enter the number of nodes and edges: ";
    cin>>nodes>>edges;
    vector<vector<int>>adj(nodes+1);
    vector<bool>visited(nodes+1, false);
    
    cout<<"Enter the edges (u v): ";
    for(int i=0;i<edges;++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int start;
    cout<<"Enter the starting node: ";
    cin>>start;
    
    DFS(start,adj,visited);
    return 0;
}

output: 
Enter the number of nodes and edges: 5 4
Enter the edges (u v): 1 2
1 3
2 4
3 5
Enter the starting node: 1
1 2 4 3 5 

=== Code Execution Successful ===