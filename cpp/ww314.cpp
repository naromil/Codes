#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kN=2048;
int n,N=3000,ta[kN],tb[kN];
inline void prep(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&ta[i],&tb[i]);
}
int f[kN][8192];
signed main(){
	prep();
	memset(f,0x3f,sizeof(f));
	f[0][N]=0;
	for(int i=1;i<=n;i++) for(int j=0;j<=(N<<1);j++){
		if(j>=N)
			f[i][N+ta[i]]=min(f[i][N+ta[i]], f[i-1][j]+ta[i]),
			f[i][j-tb[i]]=min(f[i][j-tb[i]], f[i-1][j]);
		else
			f[i][N-tb[i]]=min(f[i][N-tb[i]], f[i-1][j]+N-j),
			f[i][j+ta[i]]=min(f[i][j+ta[i]], f[i-1][j]+ta[i]);
	}
	int ans=0x3f3f3f3f;
	for(int i=0;i<=(N<<1);i++)
		ans=min(ans,f[n][i]+max(0,N-i));
	printf("%d\n",ans);
	return 0;
}
