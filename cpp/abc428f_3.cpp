#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
int n, q, a[kn];
class Sgm{
	public: int l, r, ri, op;
};
deque<Sgm> s;

signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}

	cin >> q;
	s.push_front({0, a[n], n, 0});
	for(int cs=1; cs<=q; ++cs){
		int op, x; cin >> op >> x;
		if(op == 1){
			while(!s.empty() && s.front().ri <= x) s.pop_front();
			if(!s.empty() && s.front().op == 0) continue;
			int r = (!s.empty()) ? s.front().r : a[n];
			s.push_front({r - a[x], r, x, 0});
		}
		else if(op == 2){
			while(!s.empty() && s.front().ri <= x) s.pop_front();
			if(!s.empty() && s.front().op == 1) continue;
			int l = (!s.empty()) ? s.front().l : 0;
			s.push_front({l, l + a[x], x, 1});
		}
		else{
			int lt = 0, rt = s.size() - 1, at = s.size() - 1;
			while(lt <= rt){
				int md = (lt+rt)>>1;
				if(s[md].l <= x && x < s[md].r) rt = md - 1, at = md;
				else lt = md + 1;
			}
			int ans;
			if(s[at].op == 0) ans = upper_bound(a + 1, a + n + 1, x - s[at].l) - a;
			else ans = lower_bound(a + 1, a + n + 1, s[at].r - x) - a;
			printf("%d\n", n - ans + 1);
		}
	}
	return 0;
}
/*
don't set at=-1.
check first if binary search may not find a result
*/
