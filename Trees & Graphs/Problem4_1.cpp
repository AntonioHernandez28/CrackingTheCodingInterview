#include <iostream> 
#include <vector>
#include <queue>
using namespace std; 
// directed Graph
void addEdge(vector<vector<int>> &Adj, int u, int v){
    Adj[u].push_back(v); 
}

void printGraph(vector<vector<int>> graph){
    for(int i = 0; i < graph.size(); i++){
        cout << "List of Vertex " << i << endl;
        for(auto x:graph[i]) cout << x << " "; 
        cout << endl;
    }
}

bool CanBeConnected(int nodeA, int nodeB, vector<vector<int>> graph){
    queue<int> queue; 
    vector<bool> visited(graph.size(), false); 
    visited[nodeA] = true; 
    queue.push(nodeA); 
    while(!queue.empty()){
        nodeA = queue.front(); 
        if(nodeA == nodeB) return true; 
        queue.pop();

        for(int i = 0; i < graph[nodeA].size(); i++) if(!visited[graph[nodeA][i]]) queue.push(graph[nodeA][i]);  
    }
    return false; 
}


int main(){

    /* Problem 4.1: Route Between Nodes: Given a directed graph, design an algorithm to find out whether there is a route between two nodes. */ 
    vector<vector<int>> adj(4); 
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 2); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 2, 0); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 3); 

    if(CanBeConnected(1, 3, adj)) cout << "true" << endl; 
    else cout << "false" << endl; 

}