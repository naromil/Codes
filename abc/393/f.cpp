#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,q,a[kn],f[kn],bs[kn],ans[kn];
class QUERY{
	public: int r,x,i;
	bool operator < (const QUERY &v) const {
		return r<v.r;
	}
}qs[kn];
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	memset(bs,0x3f,sizeof bs);
	cin>>n>>q;
	for(int i=1;i<=n;++i){ cin>>a[i]; }
	for(int i=1;i<=q;++i){ cin>>qs[i].r>>qs[i].x; qs[i].i=i; }
	sort(qs+1,qs+q+1);
	for(int i=1,j=1;i<=n;++i){
		f[i]=lower_bound(bs+1,bs+n+1,a[i])-bs;
		bs[f[i]]=a[i];
		for(;j<=q&&qs[j].r==i;++j){
			ans[qs[j].i]=upper_bound(bs+1,bs+n+1,qs[j].x)-bs-1;
		}
	}
	for(int i=1;i<=q;++i) printf("%d\n",ans[i]);
	return 0;
}
