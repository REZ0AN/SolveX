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
 
int MX = 10e5 + 10;

 vector<int>parent_nodes(MX, 0);

 void dfs(vector<vector<int>> &graph, int start, int parent) {

    parent_nodes[start] = parent;
     // you can write some modification logic here
     // Take action on vertex after entering the vertex
     for(auto &child : graph[start]){
         if(parent != child){
             // you can write some modification logic here
             // Take action on child before entering the child node
             dfs(graph,child, start);
             // you can write some modification logic here
             // Take action on child after coming back from the child node
         }
     }
     // you can write some modification logic here
     // Take action on vertex after coming back from the vertex
     return;
 }
 vector<int> path(int v) {
    vector<int>path;
    while(v != -1) {
        path.push_back(parent_nodes[v]);
        v = parent_nodes[v];
    }
    reverse(path.begin(),path.end());
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

    dfs(graph, 1, -1);
     int x, y;
     cin>>x>>y;
     vector<int> arr1 = path(x);
     vector<int> arr2 = path(y);
     int min_len = min(arr1.size(),arr2.size());
     int lca = -1;
     for(int i = 0; i < min_len; i++) {
        if(arr1[i] == arr2[i]) {
            lca = arr1[i];
        }
        else {
            break;
        }
     }
 
     cout<<lca<<endl;
 
 }