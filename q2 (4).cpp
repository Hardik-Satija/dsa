#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> vis;
void dfs(int x){
    vis[x]=1; cout<<x<<" ";
    for(int y:g[x]) if(!vis[y]) dfs(y);
}
int main(){
    int n,e; cin>>n>>e;
    g.resize(n); vis.assign(n,0);
    for(int i=0;i<e;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int s; cin>>s;
    dfs(s);
}
