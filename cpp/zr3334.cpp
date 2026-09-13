#include<bits/stdc++.h>
#define FILE(x) freopen(#x".in","r",stdin), freopen(#x".out","w",stdout)
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 1e6 + 16, inf = 0x3f3f3f3f, debug = 0;

int n, m;
bool operator <= (const vector<int> &A, const vector<int> &B){
    for(int j=0; j<m; ++j){
        if(A[j] > B[(j+1)%m]) return false;
    }
    return true;
}
class Block{
    public:
    int siz, g, hd = -1, bk = -1;
    vector<int> c;
};
vector<Block> c;

vector<int> rp, ps;
vector<ll> sum;
inline bool _init(const vector<vector<int>> &a){
    n = a.size(); m = a[0].size();
    rp.resize(n); sum.resize(n); ps.resize(n);

    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j) sum[i] += a[i][j];
        rp[i] = i;
    }
    stable_sort(rp.begin(), rp.end(), [](int x, int y){ return sum[x] < sum[y]; });

    vector<int> vec;
    map<vector<int>, int> mp;
    vector<int> pat(m);
    for(int i=0; i<n; ++i){
        int x = rp[i];
        vec.emp(x);

        if(i == n - 1 || sum[rp[i]] != sum[rp[i+1]]){
            Block B;
            B.siz = vec.size();
            B.g = m;
            mp.clear();
            for(int k=-min(B.siz, m); k<=min(B.siz, m); ++k){
                for(int j=0; j<m; ++j) pat[(j+k+m)%m] = a[x][j];
                if(mp.count(pat)){
                    B.g = k - mp[pat];
                    break;
                }
                mp[pat] = k;
            }
            int dif = inf, mini = inf;
            vector<int> cnt(B.g);
            for(auto j: vec){
                for(int k=0; k<m; ++k) pat[k] = a[j][k];
                if(!mp.count(pat)) return false;
                ps[j] = mp[pat];
                if(dif == inf) dif = B.g - ps[j];
                ps[j] = ((ps[j] + dif) % B.g + B.g) % B.g;
                ++cnt[ps[j]];
                B.c.emp(j);
            }
            for(int j=0; j<B.g; ++j) mini = min(mini, cnt[j]);
            int flg = 0;
            for(int j=0; j<B.g; ++j){
                if(cnt[j] == mini){
                    if(flg == 1) flg = 2;
                    else if(flg == 11) flg = 0;
                }
                else if(cnt[j] == mini + 1){
                    if(flg == 0 && j == 0 && cnt[B.g-1] == mini+1) flg = 11;
                    else if(flg == 0){ B.hd = j; flg = 1; }
                    else if(flg == 2) return false;
                }
                else return false;
            }
            vec.clear();
            c.emp(B);
        }
    }
    return true;
}

vector<int> res[kn];
vector<vector<int>> f;
vector<int> solve(const vector<vector<int>> &a){
    if(!_init(a)) return vector<int> {};
    int N = c.size();
    
    f.resize(N);
    if(c[0].hd != -1) c[0].bk = (c[0].hd + c[0].siz - 1) % c[0].g;
    for(auto x: c[0].c){
        if(c[0].bk == -1 || c[0].bk == ps[x]) f[0].emp(x);
    }
    for(int k=1; k<N; ++k){
        if(c[k].hd != -1){
            c[k].bk = (c[k].hd + c[k].siz - 1) % c[k].g;
            int u = -1;
            for(auto x: c[k].c){
                if(ps[x] == c[k].bk) f[k].emp(x);
                if(ps[x] == c[k].hd) u = x;
            }
            bool flg = false;
            for(auto z: f[k-1]){
                if(a[z] <= a[u]){ flg = true; break; }
            }
            if(!flg) return vector<int> {};
        }
        else if(c[k-1].hd != -1){
            vector<int> vis(c[k].g);
            int z = f[k-1][0];
            for(auto x: c[k].c){
                vis[(ps[x]+c[k].siz-1)%c[k].g] |= (a[z] <= a[x]);
            }
            for(auto x: c[k].c){
                if(vis[ps[x]]) f[k].emp(x);
            }
        }
        else{
            vector<int> vis(c[k].g), vis0(c[k-1].g), cmp(c[k-1].g);
            for(auto z: f[k-1]){
                vis0[ps[z]] = 1;
            }
            for(auto z: c[k-1].c){
                if(!cmp[ps[z]]) cmp[ps[z]] = (a[z] <= a[c[k].c[0]]);
            }
            for(int j=0; j<c[k].g; ++j){
                for(int jj=0; jj<c[k-1].g; ++jj){
                    if(vis0[jj]) vis[(j+c[k].siz-1)%c[k].g] |= cmp[(jj-j+c[k-1].g)%c[k-1].g];
                }
            }
            for(auto x: c[k].c){
                if(vis[ps[x]]) f[k].emp(x);
            }
        }
        if(f[k].empty()) return vector<int> {};
    }
    c[N-1].bk = ps[f[N-1][0]];

    vector<int> ans;
    for(int k=N-1; k>=0; --k){
        if(c[k].bk == -1){
            for(auto x: f[k]){
                if(a[x] <= a[ans.back()]){ c[k].bk = ps[x]; break; }
            }
            if(c[k].bk == -1) return vector<int> {};
        }
        int cnt = c[k].siz;
        for(auto x: c[k].c) res[ps[x]].emp(x);
        for(int j=c[k].bk; ; j=(j-1+c[k].g)%c[k].g){
            if(res[j].empty()){
                if(cnt == 0) break;
                else return vector<int> {};
            }
            ans.emp(res[j].back());
            res[j].pop_back();
            --cnt;
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}