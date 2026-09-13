#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
const int kN=4e5+23;
int n,q,la[kN],ra[kN];
inline void prep(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>q;
	static pair<int,int> prs[kN];
	for(int i=1;i<=n;i++) cin>>prs[i].x>>prs[i].y;
	sort(prs+1,prs+n+1,[](pair<int,int> a,pair<int,int> b){ return a.y<b.y; });;
	stack<int> stk;
	for(int i=1;i<=n;i++){
		while(!stk.empty() && prs[i].x<=prs[stk.top()].x) stk.pop();
		stk.push(i);
	}
	n=stk.size();
	for(int i=n;i>=1;i--){
		la[i]=prs[stk.top()].x;
		ra[i]=prs[stk.top()].y;
		stk.pop();
	}
}
ll t[kN<<2],v[kN<<2];
inline void pushup(int cur){
	int ls=cur<<1,rs=cur<<1|1;
	t[cur]=max(t[ls],t[rs]);
}
inline void pushdown(int cur){
	int ls=cur<<1,rs=cur<<1|1;
	t[ls]+=v[cur]; v[ls]+=v[cur];
	t[rs]+=v[cur]; v[rs]+=v[cur];
	v[cur]=0;
}
inline void update(int cur,int l,int r,int x,int y,int w){
	if(l==x&&r==y){ t[cur]+=w; v[cur]+=w; return; }
	pushdown(cur);
	int mid=(l+r)>>1,ls=cur<<1,rs=cur<<1|1;
	if(y<=mid) update(ls,l,mid,x,y,w);
	else if(x>mid) update(rs,mid+1,r,x,y,w);
	else update(ls,l,mid,x,mid,w), update(rs,mid+1,r,mid+1,y,w);
	pushup(cur);
}
signed main(){
	prep();
	for(int i=1;i<=q;i++){
		int p,x; cin>>p>>x;
		int lt=lower_bound(ra+1,ra+n+1,p)-ra;
		int rt=upper_bound(la+1,la+n+1,p)-la-1;
		if(lt<=rt) update(1,1,n,lt,rt,x);
		cout<<t[1]<<'\n';
	}
	return 0;
}
