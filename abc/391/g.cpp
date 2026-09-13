#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn=108, p=998244353;
int n,m,N;
ll f[kn][1024],ans[kn];
string s;
vector<int> nxt[1024];
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m>>s;
	N=(1<<n);
	f[0][0]=1;
	for(int k=0;k<N;++k){
		for(char ch='a';ch<='z';++ch){
			int pr=0,cr=0,ck=0;
			for(int j=0;j<n;++j){
				int o=(k>>j&1);
				if(pr+o>cr){
					ck|=(1<<j);
					cr=pr+o;
				}
				if(ch==s[j]&&pr+1>cr){
					ck|=(1<<j);
					cr=pr+1;
				}
				pr+=o;
			}
			nxt[k].emp(ck);
		}
	}
	for(int i=1;i<=m;++i){
		for(int k=0;k<N;++k){
			for(auto ck: nxt[k]){
				(f[i][ck]+=f[i-1][k])%=p;
			}
		}
	}
	for(int k=0;k<N;++k){
		int cnt=0;
		for(int j=0;j<n;++j) cnt+=(k>>j&1);
		ans[cnt]=(ans[cnt]+f[m][k])%p;
	}
	for(int i=0;i<=n;++i){ printf("%lld ",ans[i]); }
	printf("\n");
	return 0;
}
