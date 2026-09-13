#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
inline void _solv(){
	cin>>n;
	for(int k=0;k<=9;++k){
		int x=(n-k)/10, mini=min(7, ((10+n%10)-7)%10);
		while(x>0){
			mini=min(mini, (17-x%10)%10);
			x/=10;
		}
		if(mini<=k){ printf("%d\n",k); return; }
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
