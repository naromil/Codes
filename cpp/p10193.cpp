#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 5e4 + 54;
int n, m, C, R, K;
class Edge{ public: int y, w, r; }e[kn<<2];
int hd[kn], ct = 1;
inline void addedge(int x, int y, int w){
	e[++ct].y = y;
	e[ct].w = w;
	e[ct].r = hd[x];
	hd[x] = ct;
}

unordered_map<int, bool> vis[kn];
unordered_map<int, ll> dis[kn];
class Node{
	public: ll w; int x, o;
	bool operator < (const Node &nx) const { return w > nx.w; }
};
inline void dijkstra(){
	priority_queue<Node> pq;
	for(int i=1; i<=C; ++i){
		pq.push({0, i, i});
		dis[i][i] = 0;
	}
	while(!pq.empty()){
		int u = pq.top().x, o = pq.top().o; pq.pop();
		if(vis[u].count(o) || vis[u].size() >= K) continue;
		vis[u][o] = true;
		for(int j=hd[u]; j; j=e[j].r){
			int v = e[j].y;
            if(vis[v].size() >= K || dis[u][o] + e[j].w > R) continue;
			if(!dis[v].count(o) || dis[v][o] > dis[u][o] + e[j].w){
				dis[v][o] = dis[u][o] + e[j].w;
				pq.push({dis[v][o], v, o});
			}
		}
	}
}

signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> n >> m >> C >> R >> K;
	for(int i=1; i<=m; ++i){
		int x, y, w; cin >> x >> y >> w;
		addedge(x, y, w);
		addedge(y, x, w);
	}
	dijkstra();
	vector<int> ans;
	for(int i=C+1; i<=n; ++i){
		if(dis[i].size() >= K) ans.emp(i);
	}
	printf("%ld\n", ans.size());
	for(auto cr: ans) printf("%d\n", cr);
	return 0;
}
