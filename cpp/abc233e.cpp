#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=5e5+55;
int n; string str;
ll dif[kn];
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>str; n=str.size(); str=" "+str;
	for(int i=1;i<=n;++i) dif[i]=dif[i-1]+str[i]-'0';
	for(int i=n;i>=1;--i) dif[i-1]+=dif[i]/10, dif[i]%=10;
	if(dif[0]) cout<<dif[0]; for(int i=1;i<=n;++i) cout<<dif[i];
	return 0;
}
