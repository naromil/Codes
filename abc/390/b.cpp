#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,a[kn];
int gcd(int x,int y){ return y==0?x:gcd(y,x%y); }
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	if(n<=2){ printf("Yes\n"); return 0; }
	int g=gcd(a[1],a[2]), p=a[1]/g, q=a[2]/g;
	for(int i=2;i<n;++i){
		if(a[i]%p!=0 || a[i]/p*q!=a[i+1]){ printf("No\n"); return 0; }
	}
	printf("Yes\n");
	return 0;
}
