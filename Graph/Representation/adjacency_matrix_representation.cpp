/***
 * Adjacency Matrix Representation
 * IsConnected and Weight can be found in O(1)
 */

#include<vector>
#include<iostream>

using namespace std;

int main() {
    int n, m;
    cin>>n>>m;

    vector<vector<int>>graph(n+1,vector<int>(n+1,0));

    for(int i=0; i<m; i++) {
        int u, v;
        cin>>u>>v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
            cout<<graph[i][j]<< " ";
        }
        cout<<endl;
    }
}