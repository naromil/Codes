#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=3e5+35;
int n,q,sum[kn];
string str;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>q>>str; str=" "+str;
	for(int i=1;i<=n;++i) sum[i]=sum[i-1]+(str[i]==str[i-1]);
	for(int i=1;i<=q;++i){
		int x,y; cin>>x>>y;
		cout<<sum[y]-sum[x]<<'\n';
	}
	return 0;
}
