#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int cnt[kn];
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	for(int i=1;i<=7;++i){
		int x;
		cin>>x;
		++cnt[x];
	}
	int sum3=0,sum2=0;
	for(int i=1;i<=100;++i){
		if(cnt[i]>=3) ++sum3;
		else if(cnt[i]==2) ++sum2;
	}
	if(sum3>=2||sum3==1&&sum2>=1) printf("Yes\n");
	else printf("No\n");
	return 0;
}
