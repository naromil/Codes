#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=3e5+35;
int q,a[kn],lt=1,rt=0;
ll sum[kn],sumhd=0;
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>q;
	for(int i=1,op,x;i<=q;++i){
		cin>>op;
		if(op==1){
			cin>>x;
			a[++rt]=x;
			sum[rt]=sum[rt-1]+a[rt-1];
		}
		else if(op==2){
			sumhd+=a[lt];
			a[lt++]=0;
		}
		else if(op==3){
			cin>>x;
			printf("%lld\n",sum[lt+x-1]-sumhd);
		}
	}
	return 0;
}
