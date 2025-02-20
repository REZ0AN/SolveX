/** 
 * Adjacency List Representation
 * Space Consumption Optimal
 */

#include<iostream>
#include<vector>

using namespace  std;

int main() {
    int n, m;
    cin>>n>>m;
    vector<int> graph[n+1];
    for(int i = 1; i<=m; i++){
        int u, v;
        cin>>u>>v;

        // undirected graph
        graph[u].push_back(v);
        if(v != u){
            graph[v].push_back(u);
        }

    }
    
    for(int i = 1; i<=n; i++) {
        cout<< i << " : ";
        for(auto &x : graph[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }

}