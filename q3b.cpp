#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,e; cin>>n>>e;
    vector<vector<pair<int,int>>> g(n);
    for(int i=0;i<e;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    vector<int> vis(n,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    int cost=0;
    while(!pq.empty()){
        auto x=pq.top(); pq.pop();
        int w=x.first,u=x.second;
        if(vis[u]) continue;
        vis[u]=1; cost+=w;
        for(auto &p:g[u]) if(!vis[p.first]) pq.push({p.second,p.first});
    }
    cout<<cost;
}
