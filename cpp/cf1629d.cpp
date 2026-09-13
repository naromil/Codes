#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
unordered_map<string, int> mp2, mp3;
inline void _solv(){
    cin >> n;
    bool ans = false;
    mp2.clear(); mp3.clear();
    for(int i=1; i<=n; ++i){
        string u; cin >> u;
        string v = u; reverse(v.begin(), v.end()); if(u == v) ans = true;
        if(u.size() == 2){
            string s1 = {u[1], u[0]};
            if(mp2[s1]) ans = true;
            mp2[u] = mp3[u] = 1;
        }
        else if(u.size() == 3){
            string s1 = {u[2], u[1]}, s2 = {u[2], u[1], u[0]}, s3 = {u[0], u[1]};
            if(mp3[s1] || mp3[s2]) ans = true;
            mp3[u] = mp2[s3] = 1;
        }
    }
    printf(ans ? "YES\n" : "NO\n");
}
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin >> T; while(T--) _solv();
    return 0;
}