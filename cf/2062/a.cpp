#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
string str;
inline void _solv(){
	cin>>str;
	int ans=0;
	for(int i=0;i<str.size();++i){
		if(str[i]=='1') ++ans;
	}
	printf("%d\n",ans);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
