#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,X;
ll m;
string str;
inline void _solv(){
	cin>>n>>X>>m>>str;
	bool flg=false;
	for(int i=0;i<n;++i){
		if(str[i]=='L') --X;
		else if(str[i]=='R') ++X;
		--m;
		if(X==0){ flg=true; break; }
	}
	if(!flg){ printf("0\n"); return; }
	int cnt=0;
	for(int i=0;i<n;++i){
		if(str[i]=='L') --X;
		else if(str[i]=='R') ++X;
		++cnt;
		if(X==0) break;
	}
	if(cnt==n&&X!=0) printf("1\n");
	else printf("%lld\n",1+m/cnt);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
