#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string str;
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>str;
	ll x=0,y=0;
	bool flg=false;
	for(int i=0;i<str.size();++i){
		if(str[i]=='x') flg=true;
		else if(!flg) x=x*10+str[i]-'0';
		else y=y*10+str[i]-'0';
	}
	printf("%lld\n",x*y);
	return 0;
}
