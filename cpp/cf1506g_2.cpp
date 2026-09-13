#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 45;
bool ins[kn];
int n, cnt[kn];

inline string _solv(){
	string a; cin >> a; n = a.size(); a = " " + a;
	memset(ins, false, sizeof ins);
	memset(cnt, 0, sizeof cnt);

	for(int i=1; i<=n; ++i) ++cnt[a[i]-'a'];
	stack<int> stk;
	for(int i=1; i<=n; ++i){
		int x = a[i] - 'a';
		if(!ins[x]){
			while(!stk.empty() && cnt[stk.top()] && x > stk.top()){
				ins[stk.top()] = false;
				stk.pop();
			}
			stk.push(x);
			ins[x] = true;
		}
		--cnt[x];
	}

	string ans = "";
	while(!stk.empty()){
		char ch = stk.top() + 'a'; stk.pop();
		ans += ch;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin >> T;
	while(T--) cout << _solv() << '\n';
	return 0;
}
