#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=1e5+15;
int n,w,a[kn];
multiset<int> st;
multiset<int>::iterator it;
int rk;
vector<int> ans;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>w;
	cin>>a[1]; st.insert(a[1]); it=st.begin(); rk=1; ans.emplace_back(a[1]);
	for(int i=2;i<=n;++i){
		cin>>a[i];
		st.insert(a[i]);
		if(a[i]>=*it) ++rk;
		int cur_rk=max(1,i*w/100);
		while(rk<cur_rk) ++rk, --it;
		while(rk>cur_rk) --rk, ++it;
		ans.emplace_back(*it);
	}
	for(auto ntr: ans) cout<<ntr<<' ';
	return 0;
}
