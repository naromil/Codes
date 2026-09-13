#include<bits/stdc++.h>
#define FILE(x) freopen(#x".in","r",stdin), freopen(#x".out","w",stdout)
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 108;
class Struct{
	public: bool end = false;
	int cnt;
	ll len, siz;
	string t[kn], n[kn];
	unordered_map<string, int> n_tbl;
	ll st = 0, lme[kn], rme[kn];
}mem;
unordered_map<string, Struct> tps;
inline void _init(){
	mem.cnt = 1; mem.end = true;
	mem.len = mem.siz = 1; tps["byte"] = mem;
	mem.len = mem.siz = 2; tps["short"] = mem;
	mem.len = mem.siz = 4; tps["int"] = mem;
	mem.len = mem.siz = 8; tps["long"] = mem;
	mem.end = false;
	mem.len = mem.siz = mem.cnt = mem.st = 0;
}

inline ll calc(ll st, ll len){
	if(st % len == 0) return st;
	else return st - st%len + len;
}
inline ll bud(Struct &cur){
	cur.end = false;
	cur.len = cur.st = 0;
	for(int i=1; i<=cur.cnt; ++i){
		cur.len = max(cur.len, tps[cur.t[i]].len);
	}
	for(int i=1; i<=cur.cnt; ++i){
		cur.n_tbl[cur.n[i]] = i;
		cur.st = calc(cur.st, tps[cur.t[i]].len);
		cur.lme[i] = cur.st;
		cur.rme[i] = cur.st + tps[cur.t[i]].siz - 1;
		cur.st = cur.rme[i] + 1;
	}
	cur.siz = calc(cur.st, cur.len);
	return cur.siz;
}

inline ll find_var(Struct &cur, string str){
	if(cur.end || str == "") return 0;
	string nam = "", nxt = "";
	int i = 0;
	for(; i<str.size(); ++i){
		if(str[i] == '.') break;
		nam += str[i];
	}
	for(++i; i<str.size(); ++i){
		nxt += str[i];
	}
	int ps = cur.n_tbl[nam];
	return cur.lme[ps] + find_var(tps[cur.t[ps]], nxt);
}
inline string find_mem(Struct &cur, ll addr){
	if(cur.end) return (addr <= cur.siz - 1) ? "" : "ERR";
	int ps = lower_bound(cur.rme + 1, cur.rme + cur.cnt + 1, addr) - cur.rme;
	if(ps > cur.cnt || cur.lme[ps] > addr) return "ERR";
	string res = find_mem(tps[cur.t[ps]], addr - cur.lme[ps]);
	if(res == "ERR") return res;
	string str = cur.n[ps];
	if(!tps[cur.t[ps]].end) str += '.';
	str += res;
	return str;
}

int q;
signed main(){
	_init();
	cin >> q;
	for(int cs=1; cs<=q; ++cs){
		int op; cin >> op;
		if(op == 1){
			Struct cur; string str; cin >> str >> cur.cnt;
			for(int i=1; i<=cur.cnt; ++i){
				cin >> cur.t[i] >> cur.n[i];
			}
			ll res = bud(cur);
			tps[str] = cur;
			printf("%lld %lld\n", res, cur.len);
		}
		else if(op == 2){
			int ct = ++mem.cnt;
			cin >> mem.t[ct] >> mem.n[ct];
			mem.st = calc(mem.st, tps[mem.t[ct]].len);
			mem.lme[ct] = mem.st;
			mem.rme[ct] = mem.st + tps[mem.t[ct]].siz - 1;
			mem.st = mem.rme[ct] + 1;
			mem.n_tbl[mem.n[ct]] = ct;
			printf("%lld\n", mem.lme[ct]);
		}
		else if(op == 3){
			string str; cin >> str;
			printf("%lld\n", find_var(mem, str));
		}
		else if(op == 4){
			ll addr; cin >> addr;
			string res = find_mem(mem, addr);
			for(auto u: res) putchar(u);
			putchar('\n');
		}
	}
	return 0;
}