#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
int n, a[kn], q;
class Node{
    public: int i, x, y, op;
};
vector<Node> s;

signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
    }
    s.emp(Node{n, 0, a[n], 1});
    cin >> q;
    for(int cs=1; cs<=q; ++cs){
        int op, x; cin >> op >> x;
        if(op == 1){
            while(!s.empty() && s.back().i <= x) s.pop_back();
            if(!s.empty() && s.back().op == op) continue;
            int r = s.empty() ? a[n] : s.back().y;
            s.emp(Node{x, r - a[x], r, op});
        }
        else if(op == 2){
            while(!s.empty() && s.back().i <= x) s.pop_back();
            if(!s.empty() && s.back().op == op) continue;
            int l = s.empty() ? 0 : s.back().x;
            s.emp(Node{x, l, l + a[x], op});
        }
        else{
            int lt = 0, rt = s.size() - 1, at = 0;
            while(lt <= rt){
                int md = (lt + rt) >> 1;
                if(x >= s[md].x && x < s[md].y) at = md, lt = md + 1;
                else rt = md - 1;
            }
            int l = s[at].x, r = s[at].y, ans;
            if(s[at].op == 1) ans = upper_bound(a + 1, a + n + 1, x - l) - a;
            else ans = lower_bound(a + 1, a + n + 1, r - x) - a;
            printf("%d\n", n - ans + 1);
        }
    }
    return 0;
}
