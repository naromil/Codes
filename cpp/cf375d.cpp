#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kN=1e5+23;
int n,q,a[kN];
vector<int> nbr[kN];
vector<pair<int,int>> qs[kN];
int ans[kN];
inline void prep(){
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=2;i<=n;i++){
		int x,y; scanf("%d %d",&x,&y);
		nbr[x].push_back(y); nbr[y].push_back(x);
	}
	for(int i=1;i<=q;i++){
		int x,y; scanf("%d %d",&x,&y);
		qs[x].push_back({y,i});
	}
}
int siz[kN],son[kN];
void init(int cur,int pre){
	siz[cur]=1;
	for(auto nxt: nbr[cur]){
		if(nxt==pre) continue;
		init(nxt,cur);
		siz[cur]+=siz[nxt];
		if(siz[nxt]>siz[son[cur]])
			son[cur]=nxt;
	}
}
int col[kN],t[kN];
inline int lowbit(int x){ return -x&x; }
inline void update(int x,int w){
	if(!x) return;
	for(;x<=n;x+=lowbit(x)) t[x]+=w;
}
inline int query(int x){
	int ret=0;
	for(;x;x-=lowbit(x)) ret+=t[x];
	return ret;
}
void restore(int cur,int pre,int op){
	update(col[a[cur]],-1);
	update(col[a[cur]]+=op,1);
	for(auto nxt: nbr[cur])
		if(nxt!=pre) restore(nxt,cur,op);
}
void dsu(int cur,int pre,bool lar){
	for(auto nxt: nbr[cur]){
		if(nxt==pre||nxt==son[cur]) continue;
		dsu(nxt,cur,false);
	}
	if(son[cur]) dsu(son[cur],cur,true);

	update(col[a[cur]],-1);
	update(++col[a[cur]],1);
	for(auto nxt: nbr[cur]){
		if(nxt==pre||nxt==son[cur]) continue;
		restore(nxt,cur,1);
	}
	for(auto ntr: qs[cur])
		ans[ntr.second]=query(n)-query(min(n,ntr.first-1));
	if(!lar) restore(cur,pre,-1);
}
signed main(){
	prep();
	init(1,0);
	dsu(1,0,true);
	for(int i=1;i<=q;i++)
		printf("%d\n",ans[i]);
	return 0;
}
