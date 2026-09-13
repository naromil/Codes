#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int km=108,kn=1e5+15;
const double bs=1.0;
int n,N[km],a[km][kn];
double ans[km][km];
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>N[i];
		for(int j=1,x;j<=N[i];++j){
			cin>>x;
			++a[i][x];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			for(int k=1;k<kn;++k){
				ans[i][j]+=(bs*a[i][k]/N[i])*(bs*a[j][k]/N[j]);
			}
			ans[0][0]=max(ans[0][0],ans[i][j]);
		}
	}
	printf("%.12f\n",ans[0][0]);
	return 0;
}
