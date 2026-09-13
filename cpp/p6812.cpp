#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kN=1e6+23;
int n,q,a[kN];
ll t[kN<<2];
inline void update(int cur,int l,int r,int x,int w){
	if(l==r){ t[cur]+=w; return; }
	int mid=(l+r)>>1,ls=cur<<1,rs=cur<<1|1;
	if(x<=mid) update(ls,l,mid,x,w);
	else update(rs,mid+1,r,x,w);
	t[cur]=min(t[ls],t[rs]);
}
inline ll query(int cur,int l,int r,int x,int y){
	if(l==x&&r==y) return t[cur];
	int mid=(l+r)>>1,ls=cur<<1,rs=cur<<1|1;
	if(y<=mid) return query(ls,l,mid,x,y);
	else if(x>mid) return query(rs,mid+1,r,x,y);
	else return min(query(ls,l,mid,x,mid), query(rs,mid+1,r,mid+1,y));
}
signed main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		update(1,1,n,i,a[i]-a[i-1]);
	}
	for(int i=1;i<=q;i++){
		int op,l,r,w; scanf("%d%d%d",&op,&l,&r); r-=(r>n);
		if(op==1){
			scanf("%d",&w);
			update(1,1,n,l,w);
			if(r<n) update(1,1,n,r+1,-w);
		}
		else{
			if(l==r || query(1,1,n,l+1,r)>=0) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}
