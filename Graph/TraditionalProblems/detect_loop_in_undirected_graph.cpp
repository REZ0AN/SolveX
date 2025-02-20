// always thing of forest

#include<iostream>
#include<vector>
#include<utility>

using namespace std;

bool isLoop = false;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int start, int parent) {
    visited[start]= true;
    for(auto &child : graph[start]){
        isLoop = isLoop || (parent != child && visited[child]);
        if(!visited[child]){
            dfs(graph, visited, child, start);
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

    for(int i = 1; i<=n; i++) {
        if(!visited[i]) {
            dfs(graph, visited, i, 0);
            if(isLoop){
                break;
            }
        }
    }
    if(isLoop){
        cout<<"YES"<<endl;
    }else {
        cout<<"NO"<<endl;
    }
}