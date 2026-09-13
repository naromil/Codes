#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n;
string a;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>a; n=a.size(); a=" "+a;

	static vector<char> stk;
	for(int i=1;i<=n;++i){
		if(a[i]=='C'&&stk.size()>=2 && stk[stk.size()-1]=='B' && stk[stk.size()-2]=='A')
			stk.pop_back(), stk.pop_back();
		else stk.emplace_back(a[i]);
	}
	static stack<char> ans;
	while(!stk.empty()) ans.push(stk.back()), stk.pop_back();
	while(!ans.empty()) cout<<ans.top(), ans.pop();
	return 0;
}
