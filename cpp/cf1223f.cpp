#include<bits/stdc++.h>
#define SZ (dq.size())
using namespace std;
using ll=long long;
using ull=unsigned long long;
const int kN=3e5+23;
int n,a[kN];
ull has[kN];
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int t; cin>>t;
	static deque<int> dq;
	static unordered_map<ull,int> ump;
	while(t--){
		cin>>n;
		dq.clear();
		ump.clear();
		ump[0ull]=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(dq.empty() || dq.back()!=a[i]){
				dq.push_back(a[i]);
				has[SZ]=has[SZ-1]*1131303541ull+(ull)a[i];
			}
			else dq.pop_back();
			ump[has[SZ]]++;
		}

		ll ans=0ll;
		for(auto ntr: ump)
			ans+=(ntr.second-1ll)*ntr.second>>1;
		cout<<ans<<'\n';
	}
	return 0;
}
