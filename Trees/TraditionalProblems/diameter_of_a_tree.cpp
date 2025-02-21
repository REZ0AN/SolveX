#include<iostream>
#include<vector>
#include<utility>

using namespace std;

void dfs(vector<vector<int>> &graph,vector<int>&depth, int &start, int &parent) {
    for(auto &child : graph[start]){
        if(parent != child){
            depth[child] = depth[start] + 1;
            dfs(graph, depth, child, start);
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
    vector<int> depth(n,0);
    int start = 1;
    int parent = 0;
    
    // getting the node with max depth
    dfs(graph, depth, start, parent);
    int mx_d_node  = max_element(depth.begin(),depth.end()) - depth.begin();

    // getting the node from the mx_d_node and the depth represents the diameter
    depth.assign(n,0);
    dfs(graph, depth, mx_d_node, parent);

    cout<<*max_element(depth.begin(),depth.end())<<endl;

}