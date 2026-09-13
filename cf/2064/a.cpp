#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n;
string str;
inline void _solv(){
	cin>>n>>str;
	str="0"+str;
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(str[i]!=str[i-1]) ++cnt;
	}
	printf("%d\n",cnt);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
