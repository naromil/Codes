#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=12;
int n,m,a[kn];
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=m) ans+=a[i];
	}
	cout<<ans<<'\n';
	return 0;
}
