#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=1e6+16;
int n,m,a[kn],cnts[kn],ansl=-1e9,ansr=1e9;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	int sum=0;
	for(int r=1,l=1;r<=n;++r){
		cin>>a[r];
		sum+=(++cnts[a[r]]==1);
		while(l<=r && cnts[a[l]]>1) --cnts[a[l++]];
		if(sum==m && r-l<ansr-ansl) ansl=l, ansr=r;
	}
	cout<<ansl<<' '<<ansr<<'\n';
	return 0;
}
