#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,e; cin>>n>>e;
    vector<vector<int>> g(n);
    for(int i=0;i<e;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int s; cin>>s;
    vector<int> vis(n,0);
    queue<int> q;
    q.push(s); vis[s]=1;
    while(!q.empty()){
        int x=q.front(); q.pop();
        cout<<x<<" ";
        for(int y:g[x]) if(!vis[y]){ vis[y]=1; q.push(y); }
    }
}
