#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25,m=6e5;
int n,q,L[kn],R[kn],a[m+55],t[m+55],ans[m+55];
inline int lb(const int& x){ return (-x&x); }
inline void upd(int x,int w){
	for(;x<=m;x+=lb(x)){
		t[x]+=w;
	}
}
inline int qry(int x){
	int res=0;
	for(;x;x-=lb(x)){
		res+=t[x];
	}
	return res;
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i){ cin>>L[i]>>R[i]; }
	iota(a+1,a+m+1,1);
	for(int i=n;i>=1;--i){
		int LT=0, RT=0;
		int lt=1,rt=m;
		while(lt<=rt){
			int mt=(lt+rt)>>1;
			if(a[mt]+qry(mt) >= L[i]+1){
				LT=mt;
				rt=mt-1;
			}
			else{ lt=mt+1; }
		}
		lt=1,rt=m;
		while(lt<=rt){
			int mt=(lt+rt)>>1;
			if(a[mt]+qry(mt) <= R[i]+1){
				RT=mt;
				lt=mt+1;
			}
			else{ rt=mt-1; }
		}
//		printf("%d: %d %d\n",i,LT,RT);
		upd(LT,-1);
		upd(RT+1,1);
	}
	for(int i=1;i<=m;++i){ ans[a[i]+qry(i)]=i; }
	for(int i=1;i<=m;++i){ if(!ans[i]) ans[i]=ans[i-1]; }
	cin>>q;
	for(int i=1,x;i<=q;++i){
		cin>>x;
		printf("%d\n",ans[x]);
	}
	return 0;
}
