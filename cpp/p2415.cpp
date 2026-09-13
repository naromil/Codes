#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=32;
int n,N,a[kn];
void prep(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int x; while(cin>>x) a[++n]=x;
	N=n>>1;
}
bool dig[kn];
int lcnt=0;
ll lsum=0;
void dfs1(int i){
	if(i>N){
		int ret=0;
		for(int j=1;j<=N;++j) if(dig[j]) ret+=a[j];
		lsum+=ret;
		++lcnt;
		return;
	}
	dig[i]=true;
	dfs1(i+1);
	dig[i]=false;
	dfs1(i+1);
}
ll ans=0;
void dfs2(int i){
	if(i>n){
		int ret=0;
		for(int j=N+1;j<=n;++j) if(dig[j]) ret+=a[j];
		ans+=lsum+1ll*lcnt*ret;
		return;
	}
	dig[i]=true;
	dfs2(i+1);
	dig[i]=false;
	dfs2(i+1);
}
signed main(){
	prep();
	dfs1(1);
	dfs2(N+1);
	cout<<ans<<'\n';
	return 0;
}
