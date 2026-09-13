#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,N,sqn;
vector<ll> vec;
inline void add(ll d){ vec.emplace_back((d-N/d-2)/4); }
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	N=4*n-1;
	sqn=sqrt(abs(N));
	for(int i=1;i<=sqn;i+=2){
		if(N%i) continue;
		add(i);
		add(-i);
		add(N/i);
		add(-N/i);
	}
	sort(vec.begin(),vec.end());
	vec.resize(unique(vec.begin(),vec.end())-vec.begin());
	printf("%ld\n",vec.size());
	for(auto v: vec) printf("%lld ",v);
	return 0;
}
