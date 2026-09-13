#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
const int kn=5e5+55;
int n,m,d,lens[kn];
ll ans=0;
string a[kn],b[kn];
vector<int> vec[kn],nxt[kn];
inline void _init(){
	cin>>n>>m>>d;
	for(int i=1;i<=n;++i){ cin>>b[i]; }
	if(n<=m){ for(int i=1;i<=n;++i){ a[i]=" "+b[i]; } }
	else{
		for(int i=1;i<=m;++i){ a[i].resize(n+5); }
		for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) a[j][i]=b[i][j-1];
		swap(n,m);
	}
	for(int i=1;i<=n+1;++i) nxt[i].resize(m+4);
	for(int j=1;j<=m;++j) nxt[n+1][j]=n+1;
	for(int i=n;i>=1;--i){ for(int j=1;j<=m;++j){ nxt[i][j]=(a[i][j]=='#'?i:nxt[i+1][j]); } } // printf("NXT: %d %d: %d\n",i,j,nxt[i][j]); } }
}
class TreeArray{
	public:
	ll t[kn];
	inline int lb(const int &x){ return -x&x; }
	inline void clr(int x){ for(;x<=m;x+=lb(x)){ t[x]=0; } }
	inline void upd(int x,int w){ for(;x<=m;x+=lb(x)){ t[x]+=w; } }
	inline ll qry(int x){ ll res=0; for(;x;x-=lb(x)){ res+=t[x]; } return res; }
	inline ll iqry(int x){ return qry(m)-qry(x); }
};
class WidthManager{
	public:
	TreeArray Mul,Sum,Num;
	inline void add(int x){ Mul.upd(x,1ll*x*(x+1)); Sum.upd(x,1ll*x*2+1); Num.upd(x,1ll); }
	inline void del(int x){ Mul.upd(x,-1ll*x*(x+1)); Sum.upd(x,-1ll*x*2-1); Num.upd(x,-1ll); }
	inline void clr(int x){ Mul.clr(x); Sum.clr(x); Num.clr(x); }
	inline ll calc(int N){
		int D=min(m,d/N); ll res=0;
		res+=Mul.qry(D);
		res+=1ll*D*(Sum.iqry(D)-Num.iqry(D)*D);
//		printf("CALC(%d): %lld\n",D,res>>1);
		return res>>1;
	}
}G;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	_init();
	set<int> st;
	for(int L=1;L<=n;++L){
//		printf("L: %d ------------------\n\n",L);
		st.clear();
		lens[m]=1; G.add(m);
		for(int j=1;j<=m;++j){ vec[nxt[L][j]].emplace_back(j); }
		for(int R=L;R<=n;++R){
//			printf("R: %d\n",R);
			for(auto v: vec[R]){
				st.insert(v);
				auto it=st.find(v);
				int lt=0,rt=m+1;
				if(it!=st.begin()){ --it; lt=*it; ++it; }
				if(++it!=st.end()){ rt=*it; --it; }
				if(rt-lt-1){ --lens[rt-lt-1]; G.del(rt-lt-1); }
				if(v-lt-1){ ++lens[v-lt-1]; G.add(v-lt-1); }
				if(rt-v-1){ ++lens[rt-v-1]; G.add(rt-v-1); }
			}
			ans+=G.calc(R-L+1);
		}
		for(int j=1;j<=m;++j){ vec[nxt[L][j]].clear(); }
		for(int i=1;i<=m;++i) if(lens[i]){ G.clr(i); lens[i]=0; }
	}
	printf("%lld\n",ans);
	return 0;
}
