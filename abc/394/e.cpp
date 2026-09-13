#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=108;
int n,dis[kn][kn],vis[kn][kn];
vector<int> c[kn][26],b[kn][26];
class NODE{
	public: int x,y,dis;
	bool operator < (const NODE& v) const { return dis>v.dis; }
};
priority_queue<NODE> pq;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;++i){
		dis[i][i]=0;
		string str; cin>>str;
		for(int j=0;j<str.size();++j){
			if(str[j]=='-') continue;
			c[i][str[j]-'a'].emplace_back(j+1);
			b[j+1][str[j]-'a'].emplace_back(i);
			if(dis[i][j+1]) dis[i][j+1]=1;
		}
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) pq.push({i,j,dis[i][j]});
	while(!pq.empty()){
		int i=pq.top().x, j=pq.top().y; pq.pop();
		if(vis[i][j]) continue;
		vis[i][j]=1;
		for(int k=0;k<26;++k){
			for(auto u: b[i][k]){
				for(auto v: c[j][k]){
					if(dis[u][v]>dis[i][j]+2){
						dis[u][v]=dis[i][j]+2;
						pq.push({u,v,dis[u][v]});
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) printf("%d ",(dis[i][j]<0x3f3f3f3f?dis[i][j]:-1));
		printf("\n");
	}
	return 0;
}
