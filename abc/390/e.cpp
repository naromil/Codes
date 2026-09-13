#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pii pair<int,int>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn=5e3+53;
int n,m,f[5][kn];
vector<pii> a[5];
inline bool chk(int mt){
	int cm=0;
	for(int k=1;k<=3;++k){
		cm+=lower_bound(f[k]+1,f[k]+m+1,mt)-f[k];
	}
	return cm<=m;
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1,x,op,y;i<=n;++i){
		cin>>op>>x>>y;
		a[op].emp(mp(x,y));
	}
	for(int k=1;k<=3;++k){
		for(auto u: a[k]){
			for(int i=m;i>=u.y;--i){
				f[k][i]=max(f[k][i], f[k][i-u.y]+u.x);
			}
		}
	}
	int lt=0,rt=1e9;
	while(lt<=rt){
		int mt=(lt+rt)>>1;
		if(mt==lt) break;
		if(chk(mt)) lt=mt;
		else rt=mt;
	}
	printf("%d\n",lt);
	return 0;
}
