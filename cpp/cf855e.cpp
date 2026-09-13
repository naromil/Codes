#include<bits/stdc++.h>
#define MX(x,y) (x>y?x:y)
#define MN(x,y) (x<y?x:y)
#define emp emplace_back
using namespace std;
using ll=long long;
inline ll fpow(ll x,int y){ ll ret=1; while(y>0){ if(y&1) ret*=x; x*=x; y>>=1; } return ret; }
ll f[64][1024][2],mb;
inline void indp(int b){
	mb=(1<<b);
	memset(f,0,sizeof f); for(int j=1;j<mb;j<<=1) f[0][j][j==1]=1;
	for(int i=1;i<64;++i) for(int j=0;j<mb;++j) for(int k=0;k<b;++k) f[i][j]+=f[i-1][j^1<<k];
}
inline ll _solv(int b,int r){
	cerr<<r<<" =============================\n";
	if(r<b) return 1ll;
	vector<int> vc; while(r>0){ vc.emp(r%b); r/=b; } int m=vc.size();
	ll ret=f[m-2][0];
	int sts=0;
	for(int i=m-1;i>=1;--i){
		for(int k=0;k<vc[i];++k){
			ret+=f[i-1][sts^1<<k];
			cerr<<i<<' '<<(sts^1<<k)<<' '<<f[i-1][sts^1<<k]<<'\n';
		}
		sts^=1<<vc[i];
	}
	for(int k=0;k<=vc[0];++k) ret += ((sts^1<<k)==0);
	cerr<<ret<<'\n';
	return ret;
}
int q;
class QRY{ public: int b,l,r,i; bool operator < (const QRY &v) const { return b<v.b; } }qs[131072];
ll ans[131072];
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>q;
	for(int i=1;i<=q;++i) cin>>qs[i].b>>qs[i].l>>qs[i].r, qs[i].i=i;
	sort(qs+1,qs+q+1);
	for(int i=1;i<=q;++i){
		if(qs[i].b!=qs[i-1].b) indp(qs[i].b);
		ans[qs[i].i] = _solv(qs[i].b,qs[i].r) - _solv(qs[i].b,qs[i].l-1);
	}
	for(int i=1;i<=q;++i) printf("%lld\n", ans[i]);
	return 0;
}
