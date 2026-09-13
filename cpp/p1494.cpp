#include<bits/stdc++.h>
#define x first
#define y second
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define rrp(i,l,r) for(int i=l;i>=r;--i)
using namespace std;
using ll=long long;
ll gcd(ll x,ll y){ return (!y)?x:gcd(y,x%y); }
const int kN=50007;
int n,q,sqr,a[kN];
class QRY{
	public: int l,r,i;
	bool operator < (const QRY &nxt) const{
		return (l/sqr==nxt.l/sqr) ? (r<nxt.r)^(l/sqr&1) : (l/sqr<nxt.l/sqr);
	}
}qs[kN];
int cnts[kN]; // amo of each col
ll msa=0;
void _add(int ai){ msa+=cnts[ai]<<1; ++cnts[ai]; }
void _del(int ai){ --cnts[ai]; msa-=cnts[ai]<<1; }
pair<ll,ll> ans[kN];
signed main(){
	scanf("%d %d",&n,&q); sqr=ceil(1.0*n/sqrt(q)); ///
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,q) scanf("%d %d",&qs[i].l,&qs[i].r), qs[i].i=i;
	sort(qs+1,qs+q+1);
	int l=1,r=0;
	rep(i,1,q){
		if(qs[i].l==qs[i].r){ ans[qs[i].i]=make_pair(0,1); continue; }
		while(r<qs[i].r) _add(a[++r]);
		while(r>qs[i].r) _del(a[r--]);
		while(l<qs[i].l) _del(a[l++]);
		while(l>qs[i].l) _add(a[--l]);
		ll len=(r-l+1ll)*(r-l);
		ll g=gcd(msa,len);
		ans[qs[i].i].x=msa/g; ans[qs[i].i].y=len/g;
	}
	rep(i,1,q) printf("%lld/%lld\n",ans[i].x,ans[i].y);
	return 0;
}
