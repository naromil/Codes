#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=4e5+45;
int n,m,W;
class EDGE{ public: int y,w,r; }e[kn<<1];
int hd[kn],ct=1;
inline void addedge(int x,int y,int w){ e[++ct].y=y; e[ct].w=w; e[ct].r=hd[x]; hd[x]=ct; }
class PRIO{ public: int u; ll dis; bool operator < (const PRIO& v) const { return dis>v.dis; } };
ll dis[kn];
int vis[kn];
inline void dijkstra(){
    memset(dis,0x3f,sizeof dis);
    priority_queue<PRIO> pq;
    pq.push({1,0});
    dis[1]=0;
    while(!pq.empty()){
        int u=pq.top().u; pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int j=hd[u];j;j=e[j].r){
            int v=e[j].y;
            if(dis[v]>dis[u]+e[j].w){
                dis[v]=dis[u]+e[j].w;
                pq.push({v,dis[v]});
            }
        }
    }
}
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>n>>m>>W;
    for(int i=1;i<=n;++i){
        addedge(i,i+n,W);
        addedge(i+n,i,W);
    }
    for(int i=1,x,y;i<=m;++i){
        cin>>x>>y;
        addedge(x,y,1);
        addedge(y+n,x+n,1);
    }
    dijkstra();
    printf("%lld\n",min(dis[n],dis[n+n]));
    return 0;
}
