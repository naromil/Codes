#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
int n, a[kn], S, T;
vector<int> c[kn];
ll dis[kn], ans[kn];

inline void bfs(int o){
	memset(dis, 0x3f, sizeof dis);
	queue<int> q;
	dis[o] = 0;
	q.push(o);
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(auto v: c[u]){
			if(dis[v] > dis[u] + 1){
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
}

signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> n;
	S = n + 1, T = n + 2;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		if(i + a[i] <= n) c[i+a[i]].emp(i);
		if(i - a[i] >= 1) c[i-a[i]].emp(i);
		if(a[i] & 1) c[S].emp(i);
		else c[T].emp(i);
	}
	
	bfs(S);
	for(int i=1; i<=n; ++i){
		if(!(a[i] & 1)) ans[i] = (dis[i] > 1e18) ? -1 : dis[i] - 1;
	}
	bfs(T);
	for(int i=1; i<=n; ++i){
		if(a[i] & 1) ans[i] = (dis[i] > 1e18) ? -1 : dis[i] - 1;
	}
	for(int i=1; i<=n; ++i){
		printf("%lld ", ans[i]);
	}
	printf("\n");
	return 0;
}
