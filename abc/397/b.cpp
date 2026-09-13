#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string str;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>str;
	int ans=0;
	for(int i=0;i<str.size();++i){
		if(i<str.size()-1&&str[i]=='i'&&str[i+1]=='o'){ ++i; continue; }
		++ans;
	}
	printf("%d\n",ans);
	return 0;
}
