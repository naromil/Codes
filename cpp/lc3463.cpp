#include<bits/stdc++.h>
using namespace std;
class Solution {
    using ll=long long;
private:
    ll upd(ll cu,ll &c2,ll &c5){
        c2=c5=0;
        if(cu==0) return cu;
        while(cu%2==0){ ++c2; cu/=2; }
        while(cu%5==0){ ++c5; cu/=5; }
        return cu;
    }
public:
    bool hasSameDigits(string s) {
        int p=10;
        vector<int> a,co,iv={0,1,0,7,0,0,0,3,0,9},pw2={1,2,4,8,6};
        for(int i=0;i<s.size();++i){
            a.emplace_back(s[i]-'0');
        }
        int n=a.size();
        printf("N: %d\n",n);
        ll cx=1,lx=1,l2=0,l5=0,rx=n-2,r2=0,r5=0,c2=0,c5=0;
        for(int i=1;i<=n-1;++i){
            if(c2==0&&c5==0) co.emplace_back(cx);
            else if(c2>=1&&c5==0) co.emplace_back(cx*pw2[(c2-1)%4+1]%p);
            else if(c2==0&&c5>=1) co.emplace_back(cx*5%p);
            else co.emplace_back(0);
            ll llx=upd(lx,l2,l5)%p;
            ll rrx=upd(rx,r2,r5)%p;
            cx=cx*rrx%p*iv[llx]%p;
            c2=c2+r2-l2;
            c5=c5+r5-l5;
            printf("After %d: %lld %lld (%lld %lld) | ",i,lx,llx,l2,l5);
			printf("%lld %lld (%lld %lld)\n",rx,rrx,r2,r5);
            printf("*%lld/%lld: %lld %lld\n",rrx,llx,c2,c5);
            ++lx;
            --rx;
        }
        ll la=0,ra=0;
        for(int i=0;i<n-1;++i){
            printf("%d ",co[i]);
        }
        printf("\n");
        for(int i=0;i+1<n;++i){
            la=(la+a[i]*co[i])%p;
            ra=(ra+a[i+1]*co[i])%p;
        }
        // printf("%lld %lld",la,ra);
        return la==ra;
    }
}Sol;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	string s="";
	int n; n=18; while(n--) s+='1';
//	cin>>s;
	cout<<"Answer: "<<Sol.hasSameDigits(s)<<'\n';
	return 0;
}
