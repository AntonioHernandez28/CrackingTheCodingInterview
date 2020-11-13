#include <iostream>
#include <vector> 
#include <unordered_set>
using namespace std; 

vector<unordered_set<int>> makeGraph(vector<pair<int, int>> dependencies, int NumTasks){
    vector<unordered_set<int>> graph(NumTasks);  
    for(auto x:dependencies) graph[x.second].insert(x.first); 
    return graph;
}

bool dfsCycle(vector<unordered_set<int>> graph, int numTasks, int current, vector<bool> &visited, vector<bool> &onpath){
    if(visited[current]) return false; 
    onpath[current] = visited[current] = true; 
    for(auto x: graph[current]){
        if(onpath[x] || dfsCycle(graph, numTasks, x, visited, onpath)) return true; 
    }
    return onpath[current] = false;      
}

bool canBeFinished(vector<pair<int, int>> dependencies, int numTasks){
    vector<bool> visited(numTasks, false), onpath(numTasks, false); //For checking if it is current or already visited
    vector<unordered_set<int>> graph = makeGraph(dependencies, numTasks); 

    for(int i = 0; i < numTasks; i++){
        if(!visited[i] && dfsCycle(graph, numTasks, i, visited, onpath)) return false; 
    }

    return true; 
}

int main(){

    int numTasks = 2; 
  
    vector<pair<int, int> > prerequisites; 
  
    // for prerequisites: [[1, 0], [2, 1], [3, 2]] 
  
    prerequisites.push_back(make_pair(1, 0));  
 
    if (canBeFinished(prerequisites, numTasks)) { 
        cout << "Possible to finish all tasks"; 
    } 
    else { 
        cout << "Impossible to finish all tasks"; 
    } 

}