#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 4e5 + 45, bd = 1e9;
int n, ans[kn];
class Node{
    public: int x, y, z, i;
    bool operator < (const Node &nx) const {
        if(x != nx.x) return x > nx.x;
        else if(y != nx.y) return y > nx.y;
        else if(z != nx.z) return z < nx.z;
        else return i < nx.i;
    }
}a[kn], b[kn];
class SGT{
    public: int t[kn*20], ls[kn*20], rs[kn*20], tt = 0, o = 0;
    inline void pu(int u){ t[u] = t[ls[u]] + t[rs[u]]; }
    void upd(int &u, int l, int r, int x, int w){
        if(!u) u = ++tt;
        if(l == r){ t[u] += w; return; }
        int md = (l+r)>>1;
        if(x <= md) upd(ls[u], l, md, x, w);
        else upd(rs[u], md+1, r, x, w);
        pu(u);
    }
    inline void U(int x, int w){ upd(o, 1, bd, x, w); }
    int qry(int u, int l, int r, int x, int y){
        if(!u || y < l || r < x) return 0;
        else if(x <= l && r <= y) return t[u];
        int md = (l+r)>>1;
        return qry(ls[u], l, md, x, y) + qry(rs[u], md+1, r, x, y);
    }
    inline int Q(int x, int y){ return qry(o, 1, bd, x, y); }
}G;

void cdq(int L, int R){
    if(L == R) return;
    int M = (L+R)>>1;
    cdq(L, M);
    cdq(M+1, R);

    int l = L, r = M + 1, m = L;
//    printf("---------------\n");
    while(l <= M || r <= R){
        if(r > R || (l <= M && a[l].y >= a[r].y)){
            if(!a[l].i) G.U(a[l].z, 1);
//            printf("%d %d %d %d\n", a[l].x, a[l].y, a[l].z, a[l].i);
            b[m++] = a[l++];
        }
        else{
            if(a[r].i) ans[a[r].i] += G.Q(1, a[r].z);
//            printf("%d %d %d %d\n", a[r].x, a[r].y, a[r].z, a[r].i);
            b[m++] = a[r++];
        }
    }
    for(int i=L; i<=M; ++i){
        if(!a[i].i) G.U(a[i].z, -1);
    }
    for(int i=L; i<=R; ++i){
        a[i] = b[i];
    }
}

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n; ++i){
        int l, r, k; cin >> l >> r >> k;
        a[i] = {k, l + k, r - k, i};
        a[i+n] = {r - l, r, l, 0};
    }
    sort(a + 1, a + (n<<1) + 1);
//    for(int i=1; i<=(n<<1); ++i){
//        printf("%d %d %d %d\n", a[i].x, a[i].y, a[i].z, a[i].i);
//    }
    cdq(1, n<<1);
    for(int i=1; i<=n; ++i){
        printf("%d\n", ans[i] - 1);
    }
    return 0;
}