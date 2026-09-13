#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=3e5+35;
int n,m,a[kn],b[kn];
inline void _solv(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		a[i]%=m;
	}
	multiset<int> st;
	for(int i=1;i<=n;++i){
		cin>>b[i];
		b[i]%=m;
		st.insert(b[i]);
	}
	ll ans=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		auto it=st.lower_bound(m-a[i]);
		if(it==st.end()) it=st.begin();
		ans+=(a[i]+(*it))%m;
		st.erase(it);
	}
	printf("%lld\n",ans);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
