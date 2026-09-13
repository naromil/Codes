#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=1e6+16;
int n,q,a[kn];
signed main(){
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	a[0]=-1;
	for(int i=1;i<=q;++i){
		int x; scanf("%d",&x);
		int l=1,r=n,ans=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[mid]==x) r=mid-1, ans=mid;
			else if(a[mid]>x) r=mid-1;
			else l=mid+1;
		}
		cout<<ans<<' ';
	}
	return 0;
}
