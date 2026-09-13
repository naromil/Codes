#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,m,b[kn],bt=0,f[kn];
string a;
inline void _solv(){
	cin>>n>>m>>a;
	a=" "+a;
	bt=0;
	for(int i=1;i<=n;++i){ if(a[i]=='1') b[i]=++bt; }
	for(int i=1;i<=n;++i){ if(a[i]=='0') b[i]=++bt; }
	bool flg=false;
	for(int i=1;i<=n;++i){
		if(a[i]=='0') f[i]=0;
		else f[i]=f[i-1]+1;
		if(f[i]>=m) flg=true;
	}
	if(flg){ printf("NO\n"); }
	else{
		printf("YES\n");
		for(int i=1;i<=n;++i){
			printf("%d ",b[i]);
		}
		printf("\n");
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T; while(T--) _solv();
	return 0;
}
