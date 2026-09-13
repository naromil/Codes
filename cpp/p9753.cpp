#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const int kN=2e6+23;
int n;
string a;
inline void prep(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>a;
	a=" "+a;
}
ull has[kN];
signed main(){
	prep();
	static stack<int> stk;
	static unordered_map<ull,int> ump;
	ump[0ull]=1;
	for(int i=1;i<=n;i++){
		int cc=a[i]-'a'+1;
		if(stk.empty() || stk.top()!=cc){
			stk.push(cc);
			has[stk.size()]=has[stk.size()-1]*1131303541ull+(ull)cc;
		}
		else stk.pop();
		ump[has[stk.size()]]++;
	}
	ll ans=0ll;
	for(auto ntr: ump)
		ans+=(ntr.second-1ll)*ntr.second>>1;
	cout<<ans<<'\n';
	return 0;
}
