#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const int kN=1e5+23;;
int n,m;
string art[kN];
unordered_map<string,bool> rec;
unordered_map<string,int> sum;
inline void prep(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		string str; cin>>str;
		rec[str]=true;
	}
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>art[i];
}
signed main(){
	prep();
	int cnt=0,ans=0,l=1;
	for(int i=1;i<=m;i++){
		string &st=art[i];
		if(rec[st]) sum[st]++;
		if(sum[st]==1) cnt++, ans=i-l+1;
		while(l<=i){
			if(!rec[art[l]]) l++;
			else if(sum[art[l]]>=2) sum[art[l]]--, l++;
			else break;
		}
		ans=min(ans,i-l+1);
	}
	cout<<cnt<<'\n'<<ans<<'\n';
	return 0;
}
