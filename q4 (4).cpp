#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,e; cin>>n>>e;
    vector<vector<pair<int,int>>> g(n);
    for(int i=0;i<e;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    int s; cin>>s;
    vector<int> d(n,1e9);
    d[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        auto x=pq.top(); pq.pop();
        int u=x.second;
        for(auto &p:g[u]){
            int v=p.first,w=p.second;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                pq.push({d[v],v});
            }
        }
    }
    for(int i=0;i<n;i++) cout<<d[i]<<" ";
}
