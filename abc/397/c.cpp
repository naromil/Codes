#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=3e5+35;
int n,a[kn];
class NODE{
	public: int cnt[kn],ans=0;
	inline void add(int x){
		if(cnt[x]==0) ++ans;
		++cnt[x];
	}
	inline void del(int x){
		--cnt[x];
		if(cnt[x]==0) --ans;
	}
}A,B;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		B.add(a[i]);
	}
	int ans=0;
	for(int i=1;i<n;++i){
		A.add(a[i]);
		B.del(a[i]);
		ans=max(ans,A.ans+B.ans);
	}
	printf("%d\n",ans);
	return 0;
}
