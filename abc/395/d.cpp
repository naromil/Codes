#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e6+26;
int n,q,fu[kn],lb[kn],rlb[kn];
int find(int x){ return fu[x]==x?x:fu[x]=find(fu[x]); }
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>n>>q;
    for(int i=1;i<=n;++i) fu[i]=i+n;
    for(int i=n+1;i<=n+n;++i){
        fu[i]=i;
        lb[i]=i-n;
        rlb[i-n]=i;
    }
    for(int i=1,op,x,y;i<=q;++i){
        cin>>op>>x;
        if(op==1){
            cin>>y;
            fu[x]=rlb[y];
        }
        else if(op==2){
            cin>>y;
            swap(lb[rlb[x]],lb[rlb[y]]);
            swap(rlb[x],rlb[y]);
        }
        else if(op==3){
            printf("%d\n",lb[fu[x]]);
        }
    }
    return 0;
}
