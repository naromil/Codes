#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=105;
int n;
char a[kn][kn];
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j){
        a[i][j]='.';
        int idis=min(i-1,n-i), jdis=min(j-1,n-j);
        if(idis<jdis){
            if(i-1<=n-i && !(i-1&1)) a[i][j]='#';
            if(i-1>=n-i && !(n-i&1)) a[i][j]='#';
        }
        else{
            if(j-1<=n-j && !(j-1&1)) a[i][j]='#';
            if(j-1>=n-j && !(n-j&1)) a[i][j]='#';
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) printf("%c",a[i][j]);
        printf("\n");
    }
    return 0;
}
