#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 230, inf = 0x3f3f3f3f;
int n, m, S, T;
class Edge{
	public: int y, w, r;
}e[90099];
int hd[kn], ct = 1;
inline void addedge(int x, int y, int w){
	e[++ct].y = y;
	e[ct].w = w;
	e[ct].r = hd[x];
	hd[x] = ct;
	e[++ct].y = x;
	e[ct].w = 0;
	e[ct].r = hd[y];
	hd[y] = ct;
}

int lv[kn], crt[kn];
inline bool bfs(){
	memset(lv, -1, sizeof lv);
	for(int i=1; i<=T; ++i) crt[i] = hd[i];
	queue<int> q;
	q.push(S);
	lv[S] = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int j=hd[u]; j; j=e[j].r){
			int v = e[j].y;
			if(e[j].w && lv[v] == -1){
				lv[v] = lv[u] + 1;
				q.push(v);
				if(v == T) return true;
			}
		}
	}
	return false;
}
ll mxflw = 0;
inline int dinic(int u, int flw){
	if(u == T) return flw; // ++
	int rem = flw;
	for(int j=crt[u]; j&&rem; j=e[j].r){
		int v = e[j].y;
		if(lv[v] != lv[u] + 1 || !e[j].w) continue;
		int res = dinic(v, min(rem, e[j].w)); // rem -> min(rem,e[j].w)
		if(!res) lv[v] = -1;
		e[j].w -= res;
		e[j^1].w += res;
		rem -= res;
		crt[u] = j; // j+1 -> j
	}
	return flw - rem;
}

signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> m >> n;
	S = n + m + 1;
	T = S + 1;
	ll sum = 0;
	for(int i=1; i<=m; ++i){
		int w, x; cin >> w;
		sum += w;
		addedge(S, i, w);
		while(cin >> x){
			if(x == 0) break;
			addedge(i, m + x, inf);
		}
	}
	for(int i=1; i<=n; ++i){
		int x; cin >> x;
		addedge(m + i, T, x);
	}

	while(bfs()) mxflw += dinic(S, inf);
	printf("%lld\n", sum - mxflw);
	return 0;
}
