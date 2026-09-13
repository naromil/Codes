#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=108;
int n,a[kn];
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=10 && i%11>0) continue;
		int dig=i%10;
		ans+=(a[i]>=dig) + (a[i]>=dig*11);
	}
	cout<<ans<<'\n';
	return 0;
}
