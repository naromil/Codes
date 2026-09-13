#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
#define emp emplace_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,m,q,num[kn],lev[kn],nec[kn],rp[kn];
vector<int> vec;
pii a[kn];
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i].x>>a[i].y;
	}
	iota(rp+1,rp+n+1,1);
	sort(rp+1,rp+n+1,[](int x,int y){ return a[x].y<a[y].y; });
	vec.emp(0);
	for(int I=1;I<=n;++I){
		int i=rp[I], cr=++nec[a[i].x];
		lev[i]=cr;
		if(++num[cr]==m){
			vec.emp(a[i].y);
		}
	}
	cin>>q;
	for(int i=1,x,y;i<=q;++i){
		cin>>x>>y;
		int cr=upper_bound(vec.begin(),vec.end(),x)-vec.begin()-1;
		if(lev[y]>cr){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}
