#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=1e5+15;
int l,n,k,a[kn];
bool check(int mid){
	int cnt=0;
	for(int i=2;i<=n;++i) cnt+=(a[i]-a[i-1]-1)/mid;
	return cnt<=k;
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>l>>n>>k;
	for(int i=1;i<=n;++i) cin>>a[i];
	int lt=1,rt=l,ans=l;
	while(lt<=rt){
		int mid=(lt+rt)>>1;
		if(check(mid)) rt=mid-1,ans=mid;
		else lt=mid+1;
	}
	cout<<ans<<'\n';
	return 0;
}
