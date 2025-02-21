#include<iostream>
#include<vector>
#include<utility>

using namespace std;

void dfs(vector<vector<int>> &graph,vector<int>&sum, int start, int parent) {
    sum[start] += start;
    for(auto &child : graph[start]){
        if(parent != child){
            dfs(graph, sum, child, start);
            sum[start]+=sum[child];
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
    vector<int> sub_tree_sum(n+1,0);
    dfs(graph, sub_tree_sum, 1, 0);

    int i;
    long long ans = 0;
    for(i = 2; i<=n; i++) {
        int sum1 = sub_tree_sum[i];
        int sum2 = sub_tree_sum[1] - sum1;
        
        ans = max(ans, sum1*sum2*1LL);
    }

    cout<<ans<<endl;
}