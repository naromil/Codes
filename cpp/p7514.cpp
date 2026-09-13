#include<bits/stdc++.h>
#define C(x) (x>n?x-n:x+n)
using namespace std;
using ll=long long;
const int kn=2e6+26,inf=0x3f3f3f3f;
int n,m,N,a[kn],rp[kn];
void prep(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	N=(n<<1);
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		cin>>a[i+n];
	}
	iota(rp+1,rp+N+1,1);
	sort(rp+1,rp+N+1,[](int x,int y){ return a[x]<a[y]; });
}
int mima[kn];
void part1(){
	int i=0,M=0;
	for(int I=N;I>=1;I--){
		i=rp[I];
		mima[M]=a[i];
		if(a[i]<a[C(i)]){
			break;
		}
		M+=(i<=n);
	}
	for(int j=M;j<=m;++j){
		mima[j]=a[i];
	}
}
int ans=inf,maxi=-inf;
void part2(){
	for(int I=1;I<=N;++I){
		int i=rp[I];
//		cout<<a[i]<<' '<<maxi<<' '<<mima[m]<<'\n';
		ans=min(ans,max(mima[m],maxi)-a[i]);
		m-=(i<=n);
		maxi=max(maxi,a[C(i)]);
		if(m<0||a[i]>a[C(i)]){
			return;
		}
	}
}
signed main(){
	prep();
	part1();
	part2();
	cout<<ans<<'\n';
	return 0;
}
