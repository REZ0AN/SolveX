#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int>parent;

void bfs(int start,int dest, const vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    parent.assign(graph.size(),0);
    visited[start] = true;
    parent[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }
}

vector<int> give_path(int v, int s) {
    vector<int> path;
    path.push_back(v);
    while(v != s) {
        path.push_back(parent[v]);
        v = parent[v];
    }
    reverse(path.begin(), path.end());  
    return path;
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
    int startNode, destNode;
    cin>>startNode>>destNode;

    bfs(startNode, destNode, graph);
    vector<int> path = give_path(destNode, startNode);
    
    for(auto &x : path){
        cout<<x<<" -> ";
    }
    cout<<endl;

    return 0;
}