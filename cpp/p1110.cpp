#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=5e5+55,inf=0x3f3f3f3f;
int n,q,a[kn],c[kn];
multiset<int> st,mg;
int msg=inf;
void update(int w){
	st.insert(w);
	set<int>::iterator it=st.find(w);
	if(it!=st.begin()){
		--it;
		msg=min(msg,w-*it);
		++it;
	}
	if(++it!=st.end()){
		msg=min(msg,*it-w);
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		c[i]=a[i];
		if(i>=2){
			mg.insert(abs(a[i]-a[i-1]));
		}
		update(a[i]);
	}
	for(int i=1;i<=q;++i){
		string op;
		cin>>op;
		if(op=="INSERT"){
			int x,w;
			cin>>x>>w;
			if(x<n){
				mg.erase(mg.find(abs(a[x+1]-c[x])));
				mg.insert(abs(a[x+1]-w));
			}
			mg.insert(abs(w-c[x]));
			update(w);
			c[x]=w;
		}
		else if(op=="MIN_GAP"){
			cout<<*mg.begin()<<'\n';
		}
		else{
			cout<<msg<<'\n';
		}
	}
	return 0;
}
