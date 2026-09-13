#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,q,a[kn],suf[32][kn],nxt[32][kn];
inline void _solv(){
	cin>>n>>q;
	for(int i=1;i<=n;++i){ cin>>a[i]; }
	for(int k=30;k>=0;--k) for(int i=0;i<=n+1;++i){ suf[k][i]=nxt[k][i]=0; }
	for(int k=30;k>=0;--k){
		for(int i=n;i>=1;--i){ suf[k][i]=suf[k][i+1]^(a[i]>>k&1); }
		for(int i=1;i<=n;++i){ nxt[k][i]=((a[i]>>k&1)==1?i:nxt[k][i-1]); }
	}
	for(int i=1,x;i<=q;++i){
		cin>>x;
		int l=1,r=n;
		for(int k=30;k>=0;--k){
			int j=(x>>k&1)^suf[k][r+1];
			if(j==0){
				if(nxt[k][r]>=l) l=nxt[k][r]+1;
			}
			else{
				if(nxt[k][r]<r) r=nxt[k][r];
				if(r>0&&nxt[k][r-1]>=l) l=nxt[k][r-1]+1;
			}
//			for(int i=1;i<=n;++i) printf("%d ",a[i]>>k&1);
//			printf(": %d : %d %d\n",j,l,r);
			if(l>r) break;
		}
		printf("%d ",n-l+1);
	}
	printf("\n");
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
