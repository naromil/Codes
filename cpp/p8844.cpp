#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kN=1e5+23;
int n,q,dep[kN];
vector<int> nbr[kN];
vector<pair<int,int>> qs[kN];
int ans[kN];
bool is_ans[kN];
inline void prep(){
	scanf("%d %d",&n,&q);
	for(int i=2;i<=n;i++){
		int x,y; scanf("%d %d",&x,&y);
		nbr[x].push_back(y); nbr[y].push_back(x);
	}
	for(int i=1,dep=0;i<=q;i++){
		int op,x; scanf("%d %d",&op,&x);
		if(op==1) dep=x;
		else qs[x].push_back({dep,i}), is_ans[i]=true;
	}
}
class SEGT{
	public: int val,ls,rs;
}t[kN<<5];
int rt[kN],tot=0;
void update(int &cur,int l,int r,int x,int w){
	if(!cur) cur=++tot;
	if(l==r){
		t[cur].val+=w;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid) update(t[cur].ls,l,mid,x,w);
	else update(t[cur].rs,mid+1,r,x,w);
	t[cur].val=t[t[cur].ls].val+t[t[cur].rs].val;
}
int query(int cur,int l,int r,int x,int y){
	if(!cur) return 0;
	if(l==x&&r==y)
		return t[cur].val;
	int mid=(l+r)>>1;
	if(y<=mid) return query(t[cur].ls,l,mid,x,y);
	else if(x>mid) return query(t[cur].rs,mid+1,r,x,y);
	else return query(t[cur].ls,l,mid,x,mid) + query(t[cur].rs,mid+1,r,mid+1,y);
}
int merge(int cur,int nxt,int l,int r){
	if(!cur||!nxt)
		return cur|nxt;
	else if(l==r){
		t[cur].val+=t[nxt].val;
		return cur;
	}
	int mid=(l+r)>>1;
	t[cur].ls=merge(t[cur].ls,t[nxt].ls,l,mid);
	t[cur].rs=merge(t[cur].rs,t[nxt].rs,mid+1,r);
	t[cur].val=t[t[cur].ls].val+t[t[cur].rs].val;
	return cur;
}
void dfs(int cur,int pre){
	dep[cur]=dep[pre]+1;
	for(auto nxt: nbr[cur]){
		if(nxt==pre) continue;
		dfs(nxt,cur);
		rt[cur]=merge(rt[cur],rt[nxt],1,n);
	}
	update(rt[cur],1,n,dep[cur],1);
	for(auto ntr: qs[cur])
		ans[ntr.second]=(ntr.first) ? query(rt[cur],1,n,ntr.first,n) : 0;
}
signed main(){
	prep();
	dfs(1,0);
	for(int i=1;i<=q;i++)
		if(is_ans[i]) printf("%d\n",ans[i]);
	return 0;
}
