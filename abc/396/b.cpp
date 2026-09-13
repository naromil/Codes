#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,a[kn];
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>n;
    stack<int> stk;
    for(int i=1,x,y;i<=n;++i){
        cin>>x;
        if(x==1){
            cin>>y;
            stk.push(y);
        }
        else{
            if(!stk.empty()){
                printf("%d\n",stk.top());
                stk.pop();
            }
            else printf("0\n");
        }
    }
    return 0;
}
