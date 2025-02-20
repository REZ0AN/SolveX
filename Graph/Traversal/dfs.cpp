/**
 * DFS: Depth First Search
 * Graph Traversal Algorithm
 * Time Complexity: O(V+E)
 * Space Complexity: O(V)
 * 
 * You can use global declaration of graph and visited array
 * or you can pass them as reference to the function
 */

#include<iostream>
#include<vector>
#include<utility>

using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int start) {
    cout<<start<<"->";
    visited[start]= true;
    for(auto &child : graph[start]){
        if(!visited[child]){
            dfs(graph, visited, child);
        }
    }
    return;
}

int main() {
    int n, m;
    cin>>n>>m;

    vector<vector<int>> graph(n+1);

    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        if(v != u){
            graph[v].push_back(u);
        }

    }
    vector<bool>visited(n,false);

    dfs(graph, visited, 1);

    cout<<endl;

}