#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 3e5 + 35;
int n, m, X, Y, ans[kn];
class Node{
    public: int xl, xr, yl, yr;
    bool operator < (const Node &nx) const { return xr < nx.xr; }
};
multiset<Node> ms;
multiset<int> st;

inline int calc(Node cr){
    int x = (cr.xl <= X && X <= cr.xr ? X : (X < cr.xl ? cr.xl : cr.xr));
    int y = (cr.yl <= Y && Y <= cr.yr ? Y : (Y < cr.yl ? cr.yl : cr.yr));
    return sqrt(1ll * x * x + 1ll * y * y) + abs(x - X) + abs(y - Y);
}
inline void mdf(multiset<Node>::iterator &it, int x, int y){
    Node cr = *it;
    if(y < cr.yl) cr.xl = x;
    else if(y > cr.yr) cr.xr = x;
    else if(x < cr.xl) cr.yl = y;
    else if(x > cr.xr) cr.yr = y;
    st.erase(st.find(calc(*it))); ms.erase(it);
    ms.insert(cr); st.insert(calc(cr));
    it = ms.find(cr);
}

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> m >> X >> Y;
    ms.insert((Node){0, (int)1e6, 0, (int)1e6});
    st.insert(calc(*ms.begin()));
    ans[0] = *st.begin();

    for(int i=1; i<=n; ++i){
        int s, x, y; cin >> s >> x >> y;
        auto it = ms.lower_bound((Node){0, x, 0, 0}); // 1st xr >= x
        if(it != ms.end() && it->xl <= x && it->yl <= y && y <= it->yr){
            Node nl = {it->xl, x, it->yl, y};
            Node nr = {x, it->xr, y, it->yr};
            ms.insert(nl); st.insert(calc(nl));
            ms.insert(nr); st.insert(calc(nr));
            st.erase(st.find(calc(*it))); ms.erase(it);
        }
        else if(it != ms.end() && (it->xl <= x && it->yr < y || it->xl > x && it->yl <= y)){
            if(it->xl <= x){
                mdf(it, x, y);
                it = next(it);
            }
            while(it != ms.end() && y >= it->yl){
                if(y > it->yr){
                    it = next(it);
                    st.erase(st.find(calc(*prev(it)))); ms.erase(prev(it));
                }
                else{
                    mdf(it, x, y);
                    break;
                }
            }
        }
        else{
            if(it != ms.end() && it->xl <= x)
                mdf(it, x, y);
            if(it != ms.begin())
                it = prev(it);
            while(y <= it->yr){
                if(it != ms.begin() && y < it->yl){
                    it = prev(it);
                    st.erase(st.find(calc(*next(it)))); ms.erase(next(it));
                }
                else if(it == ms.begin() && y < it->yl){
                    st.erase(st.find(calc(*it))); ms.erase(it);
                    break;
                }
                else{
                    mdf(it, x, y);
                    break;
                }
            }
        }
        ans[s] = *st.begin();
    }

    for(int i=0; i<m; ++i){
        if(i) ans[i] = max(ans[i], ans[i-1]);
        printf("%d\n", ans[i]);
    }
    return 0;
}