#include<bits/stdc++.h>
#define emp emplace_back
#define MX(x,y) (x>y?x:y)
#define MN(x,y) (x<y?x:y)
using namespace std;
using ll=long long;
const int kn=1024;
int n,m,hd[kn],ct=1,L,R,ans=-1;
class EDGE{ public: int y,wl,wr,r; }e[8192];
inline void cnct(int x,int y,int wl,int wr){ e[++ct].y=y; e[ct].wl=wl; e[ct].wr=wr; e[ct].r=hd[x]; hd[x]=ct; }
int fu[kn];
inline int find(int x){ return fu[x]==x?x:fu[x]=find(fu[x]); }
inline void unin(int x,int y){ if(find(x)!=find(y)) fu[find(y)]=find(x); }
inline bool chk(){
	for(int i=1;i<=n;++i) fu[i]=i;
	for(int u=1;u<=n;++u) for(int j=hd[u];j;j=e[j].r) if(e[j].wl<=L && R<=e[j].wr) unin(u, e[j].y);
	return (find(1)==find(n));
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1,x,y,wl,wr;i<=m;++i){ cin>>x>>y>>wl>>wr; cnct(x,y,wl,wr); cnct(y,x,wl,wr); }
	for(int j=2;j<=ct;j+=2){
		L=e[j].wl;
		int lm=L,rm=1e6,am=-1;
		while(lm<=rm){
			R=lm+rm>>1;
			if(chk()) lm=R+1, am=R;
			else rm=R-1;
		}
		if(~am) ans=MX(ans, am-L+1);
	}
	if(~ans) printf("%d\n",ans);
	else printf("Nice work, Dima!\n");
	return 0;
}
