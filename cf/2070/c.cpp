#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=3e5+35;
int n,m,a[kn];
string str;
inline void _solv(){
	cin>>n>>m>>str;
	for(int i=1;i<=n;++i){ cin>>a[i]; }
	for(int i=0;i<n;++i){
		if(i==n-1||str[i+1]!=str[i]){
		}
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
