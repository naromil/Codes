#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kN=5e5+23,ninf=0xc1c1c1c1;
int n;
char a[kN];
vector<int> nbr[kN];
inline void prep(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	for(int i=2;i<=n;i++){
		int x; cin>>x>>a[i];
		nbr[x].push_back(i); nbr[i].push_back(x);
	}
}
int way[kN],siz[kN],son[kN],dep[kN];
inline int calc(int cur,char nxt){ int cc=nxt-'a'; return cur^(1<<cc); }
inline void init(int cur,int pre){
	if(pre) way[cur]=calc(way[pre],a[cur]);
	dep[cur]=dep[pre]+1;
	siz[cur]=1;
	for(auto nxt: nbr[cur]){
		if(nxt==pre) continue;
		init(nxt,cur);
		if(siz[nxt]>siz[son[cur]]) son[cur]=nxt;
		siz[cur]+=siz[nxt];
	}
}
int ans[kN],cnts[4444444];
inline int qry(int cur,int pre){
	int ret=dep[cur]+cnts[way[cur]];
	for(int i=0;i<22;i++)
		ret=max(ret,dep[cur]+cnts[way[cur]^(1<<i)]);
	for(auto nxt: nbr[cur]){
		if(nxt==pre) continue;
		ret=max(ret,qry(nxt,cur));
	}
	return ret;
}
inline void usd(int cur,int pre,bool op,bool rot=false){
	if(op&&rot){
		ans[cur]=max(ans[cur],cnts[way[cur]]-dep[cur]);
		for(int i=0;i<22;i++)
			ans[cur]=max(ans[cur],cnts[way[cur]^(1<<i)]-dep[cur]);
	}
	cnts[way[cur]]=op ? max(cnts[way[cur]],dep[cur]) : ninf;
	for(auto nxt: nbr[cur]){
		if(nxt==pre || op&&rot&&nxt==son[cur]) continue;
		if(op&&rot) ans[cur]=max(ans[cur],qry(nxt,cur)-(dep[cur]<<1));
		usd(nxt,cur,op);
	}
}
inline void dsu(int cur,int pre,bool lar){
	for(auto nxt: nbr[cur]){
		if(nxt==pre || nxt==son[cur]) continue;
		dsu(nxt,cur,false);
		ans[cur]=max(ans[cur],ans[nxt]);
	}
	if(son[cur]) dsu(son[cur],cur,true), ans[cur]=max(ans[cur],ans[son[cur]]);
	usd(cur,pre,true,true);
	if(!lar) usd(cur,pre,false,true);
}
signed main(){
	prep();
	init(1,0);
	memset(cnts,0xc1,sizeof(cnts));
	dsu(1,0,true);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<' ';
	return 0;
}
