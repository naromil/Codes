#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,a[kn],b[kn],cnta=0,cntb=0;
unordered_map<int,bool> mpa,mpb;
inline void _solv(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(!mpa[a[i]]){
			mpa[a[i]]=true;
			++cnta;
		}
	}
	for(int i=1;i<=n;++i){
		cin>>b[i];
		if(!mpb[b[i]]){
			mpb[b[i]]=true;
			++cntb;
		}
	}
	if(cnta>=2 && cntb>=2) printf("YES\n");
	else if(cnta>=3 || cntb>=3) printf("YES\n");
	else printf("NO\n");
	mpa.clear();
	mpb.clear();
	cnta=cntb=0;
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
