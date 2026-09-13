#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=3e5+35;
int n,a[kn];
unordered_map<int,int> vis;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		++vis[a[i]];
	}
	int ans=-1,ps=-1;
	for(int i=1;i<=n;++i){
		if(vis[a[i]]==1){
			if(a[i]>ans){
				ans=a[i];
				ps=i;
			}
		}
	}
	printf("%d\n",ps);
	return 0;
}
