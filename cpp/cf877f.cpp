#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define rrp(i,l,r) for(int i=l;i>=r;--i)
#define pb emplace_back
using namespace std;
using ll=long long;
const int kN=1e5+23;
int n,m,sqr,q,vs[kN][3];
class QRY{
	public: int l,r,i;
	bool operator < (const QRY &nxt) const{
		return l/sqr==nxt.l/sqr ? r!=nxt.r&&(r<nxt.r^l/sqr&1) : l<nxt.l;
	}
}qs[kN];
void prep(){
	static int t[kN],a[kN];
	static ll sum[kN];
	static vector<ll> disc;
	scanf("%d %d",&n,&m);
	rep(i,1,n)
		scanf("%d",&t[i]);
 
	ll s[]={0,0};
	rep(i,1,n){
		scanf("%d",&a[i]);
		s[t[i]-1]+=a[i];
		sum[i]=s[0]-s[1];
		disc.pb(sum[i]), disc.pb(sum[i]-m), disc.pb(sum[i]+m);
	}
	disc.pb(0), disc.pb(-m), disc.pb(m);
 
	sort(disc.begin(),disc.end());
	int len=unique(disc.begin(),disc.end())-disc.begin();
	rep(i,0,n)
		vs[i][0]=lower_bound(disc.begin(),disc.begin()+len,sum[i])-disc.begin()+1,
		vs[i][1]=lower_bound(disc.begin(),disc.begin()+len,sum[i]-m)-disc.begin()+1,
		vs[i][2]=lower_bound(disc.begin(),disc.begin()+len,sum[i]+m)-disc.begin()+1;
 
	scanf("%d",&q); sqr=ceil(n/sqrt(q));
	rep(i,1,q) scanf("%d %d",&qs[i].l,&qs[i].r), qs[i].l--, qs[i].i=i;
	sort(qs+1,qs+q+1);
}
ll ans[kN],msa=0;
int cnts[kN<<2];
inline void _add(const short op,int i){ msa+=cnts[vs[i][op]]; cnts[vs[i][0]]++; }
inline void _del(const short op,int i){ cnts[vs[i][0]]--; msa-=cnts[vs[i][op]]; }
signed main(){
	prep();
 
	int l=0,r=-1;
	for(int i=1;i<=q;i++){
		while(r<qs[i].r) _add(1,++r);
		while(r>qs[i].r) _del(1,r--);
		while(l<qs[i].l) _del(2,l++);
		while(l>qs[i].l) _add(2,--l);
		ans[qs[i].i]=msa;
	}
	for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
	return 0;
}
