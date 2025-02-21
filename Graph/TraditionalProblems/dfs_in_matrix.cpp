#include<iostream>
#include<vector>
#include<utility>

using namespace std;

// king moves
int dx8[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy8[] = {1, 0, -1, 1, -1, 1, 0, -1};

// rookie moves
int dx4[] = {1, -1, 0, 0};
int dy4[] = {0, 0, 1, -1};



bool isAchievable = false;

bool isPossible(int newX,int newY, vector<vector<char>> &graph, vector<vector<bool>> &visited) {
    if(newX >= graph.size() || newX < 1  || newY >= graph[0].size() || newY < 1 ) return false;
    return !visited[newX][newY] && graph[newX][newY] != '#';
}


void dfs(vector<vector<char>> &graph, vector<vector<bool>> &visited, int x, int y, int tx, int ty) {
    visited[x][y]=true;
    for(int i = 0 ; i < 4; i++) {
        int newX = x + dx4[i];
        int newY = y + dy4[i];
        if(isPossible(newX,newY, graph, visited)) {
            if(tx == newX && ty == newY) {
                isAchievable = true | isAchievable;
            }
            dfs(graph, visited, newX, newY, tx, ty);
        }

    }
    return;
}

int main() {
    int n, m;
    cin>>n>>m;
    vector<vector<char>> graph(n+1,vector<char>(m+1));
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++) {
            char ch;
            cin>>ch;
            graph[i][j]= ch;
        }
    }
    int x, y, tx, ty;
    cin>>x>>y>>tx>>ty;
    vector<vector<bool>>visited(n+1, vector<bool>(m+1,false));
    dfs(graph, visited, x, y, tx, ty);
    if(isAchievable)
        cout<<"YES\n";
    else 
        cout<<"NO\n";

}