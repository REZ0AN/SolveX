#include<iostream>
#include<vector>
#include<utility>

using namespace std;

void dfs(vector<vector<int>> &graph,vector<int>&depth,vector<int>&height, int start, int parent) {
    for(auto &child : graph[start]){
        if(parent != child){
            depth[child] = depth[start] + 1;
            dfs(graph, depth, height, child, start);
            height[start] = max(height[child]+1, height[start]);
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
    vector<int> depth(n+1,0);
    vector<int> height(n+1,0);
    dfs(graph, depth, height, 1, 0);
    cout<<"Depth: ";
    for(auto x: depth){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"Height: ";
    for(auto x: height){
        cout<<x<<" ";
    }
    cout<<endl;

}