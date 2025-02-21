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
 
 void dfs(vector<vector<int>> &graph, int start, int parent) {
     // visualizing the path
     cout<<start<<" -> ";
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
     dfs(graph, 1, 0);
 
     cout<<endl;
 
 }