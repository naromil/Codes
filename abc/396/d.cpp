#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=12;
int n,m;
ll ans=0x3f3f3f3f3f3f3f3f;
class EDGE{ public: int y; ll w; int r; }e[1024];
int hd[kn],ct=1;
inline void addedge(int x,int y,ll w){ e[++ct].y=y; e[ct].w=w; e[ct].r=hd[x]; hd[x]=ct; }
void dfs(const int& u,const ll& w,const int& pth){
    if(u==n){
        ans=min(ans,w);
        return;
    }
    for(int j=hd[u];j;j=e[j].r){
        if(pth&1<<(e[j].y-1)) continue;
        int v=e[j].y;
        dfs(v,w^e[j].w,pth^1<<(e[j].y-1));
    }
}
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int x,y; ll w;
        cin>>x>>y>>w;
        addedge(x,y,w);
        addedge(y,x,w);
    }
    dfs(1,0,1);
    printf("%lld\n",ans);
    return 0;
}
