#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=4e5+45;
int n,R,C;
string a;
map<int,map<int,int>> mp;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>R>>C>>a;
	a=" "+a;
	for(int i=1;i<=n;++i){
		if(mp[R][C]==0) mp[R][C]=i;
		if(a[i]=='N') --R;
		else if(a[i]=='S') ++R;
		else if(a[i]=='W') --C;
		else if(a[i]=='E') ++C;
	}
	R=0; C=0;
	for(int i=1;i<=n;++i){
		if(a[i]=='N') --R;
		else if(a[i]=='S') ++R;
		else if(a[i]=='W') --C;
		else if(a[i]=='E') ++C;
		int ret=mp[R][C];
		if(ret&&i>=ret) printf("1");
		else printf("0");
	}
	printf("\n");
	return 0;
}
