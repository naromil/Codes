#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[60];
int b[60];
map<int,int> mp;

void solve(){
    cin>>n;
    long long s1=0,s2=0;
    mp.clear();
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!mp.count(a[i])){
            s1++;
            mp[a[i]]=1;
        }
    }
    mp.clear();
    for(int i=1;i<=n;i++){
        cin>>b[i];
        if(!mp.count(b[i])){
            s2++;
            mp[b[i]]=1;
        }
    }
    if(s1*s2>=3){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
