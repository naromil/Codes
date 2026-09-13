#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,l,r;
string s;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>l>>r>>s;
	s=" "+s;
	bool flg=false;
	for(int i=l;i<=r;++i){
		if(s[i]!='o') flg=true;
	}
	if(!flg) printf("Yes\n");
	else printf("No\n");
	return 0;
}
