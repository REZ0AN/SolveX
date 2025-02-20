#include<iostream>
#include<vector>
#include<utility>

using namespace std;

vector<vector<int>> connect_components;
vector<int> current_component;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int start) {
    current_component.push_back(start);
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
    

    for(int i = 1; i <= n; i++) {
       if(!visited[i]) {
           dfs(graph,visited,i);
           connect_components.push_back(current_component);
           current_component.clear();
       }
    }

    cout<<"No of Connected Components Found: "<<connect_components.size()<<endl;
    for(auto &connected_component : connect_components) {
        cout<<"{ ";
        for(auto &node: connected_component) {
            cout<<node<<" ";
        }
        cout<<"}\n";
    }

}