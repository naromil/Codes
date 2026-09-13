#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kN=1e5+23;
int n,a[kN];
inline bool cmp(int x,int y){
	return x<y;
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
	return 0;
}
