#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
int n, q, a[kn];
class Sgm{
	public: int l, r, li, ri, op;
};
deque<Sgm> s;

signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}

	s.push_front({0, a[n], 1, n, 0});
	for(int i=1; i<=q; ++i){
		int op, x; cin >> op >> x;
		if(op == 1){
			while(!s.empty() && s.front().ri <= x) s.pop_front();
			if(!s.empty() && s.front().op == 0) continue;
			if(!s.empty()) s.front().li = x + 1;
			int r = (!s.empty()) ? s.front().r : a[n];
			s.push_front({r - a[x], r, 1, x, 0});
		}
		else if(op == 2){
			while(!s.empty() && s.front().ri <= x) s.pop_front();
			if(!s.empty() && s.front().op == 1) continue;
			if(!s.empty()) s.front().li = x + 1;
			int l = (!s.empty()) ? s.front().l : 0;
			s.push_front({l, l + a[x], 1, x, 1});
		}
		else{
			int lt = 0, rt = s.size() - 1, at = -1;
			while(lt <= rt){
				int md = (lt+rt)>>1;
				if(s[md].l <= x && x < s[md].r) rt = md - 1, at = md;
				else lt = md + 1;
			}
			int li = s[at].li, ri = s[at].ri, y = -1;
			if(s[at].op == 0) y = upper_bound(a + li, a + ri + 1, x - s[at].l) - a;
			else y = lower_bound(a + li, a + ri + 1, s[at].r - x) - a;
			printf("%d\n", y);
		}
	}
	return 0;
}
