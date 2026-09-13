#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=8e3+83;
int n,q,pos[kn];
pair<int,int> a[kn];
void update(int rp,int w){
	a[rp].first=w;
	while(rp<n && a[rp]>a[rp+1]) swap(a[rp],a[rp+1]), swap(pos[a[rp].second],pos[a[rp+1].second]), ++rp;
	while(rp>1 && a[rp]<a[rp-1]) swap(a[rp],a[rp-1]), swap(pos[a[rp].second],pos[a[rp-1].second]), --rp;
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;++i) cin>>a[i].first, a[i].second=i;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) pos[a[i].second]=i;
	for(int i=1;i<=q;++i){
		int op,x,w; cin>>op>>x;
		if(op==1) cin>>w, update(pos[x],w);
		else cout<<pos[x]<<'\n';
	}
	return 0;
}
