#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=5e4+54;
int n,q,a[kn],st[kn][20],ts[kn][20];
void st_init(){
	for(int k=1;(1<<k)<=n;++k) for(int i=1;i+(1<<k)-1<=n;++i){
		st[i][k] = max(st[i][k-1], st[i+(1<<k-1)][k-1]);
		ts[i][k] = min(ts[i][k-1], ts[i+(1<<k-1)][k-1]);
	}
}
int calc_st(int l,int r){
	int len=log2(r-l+1);
	return max(st[l][len], st[r-(1<<len)+1][len]);
}
int calc_ts(int l,int r){
	int len=log2(r-l+1);
	return min(ts[l][len], ts[r-(1<<len)+1][len]);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
		cin>>a[i], st[i][0]=ts[i][0]=a[i];
	st_init();
	vector<int> ans;
	for(int i=1;i<=q;++i){
		int l,r; cin>>l>>r;
		ans.emplace_back(calc_st(l,r)-calc_ts(l,r));
	}
	for(auto ntr: ans) cout<<ntr<<'\n';
	return 0;
}
