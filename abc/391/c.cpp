#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e6+26;
int n,q,pos[kn],num[kn],ans=0;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		pos[i]=i;
		num[i]=1;
	}
	for(int i=1,op,x,y;i<=q;++i){
		cin>>op;
		if(op==1){
			cin>>x>>y;
			--num[pos[x]];
			if(num[pos[x]]==1) --ans;
			pos[x]=y;
			if(num[pos[x]]==1) ++ans;
			++num[pos[x]];
		}
		else if(op==2){
			printf("%d\n",ans);
		}
	}
	return 0;
}
