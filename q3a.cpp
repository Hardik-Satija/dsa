#include <bits/stdc++.h>
using namespace std;
int f[10000];
int findp(int x){ return f[x]==x?x:f[x]=findp(f[x]); }
int main(){
    int n,e; cin>>n>>e;
    vector<array<int,3>> edges;
    for(int i=0;i<n;i++) f[i]=i;
    for(int i=0;i<e;i++){
        int u,v,w; cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
    sort(edges.begin(),edges.end());
    int cost=0;
    for(auto &it:edges){
        int w=it[0],u=it[1],v=it[2];
        u=findp(u); v=findp(v);
        if(u!=v){ cost+=w; f[u]=v; }
    }
    cout<<cost;
}
