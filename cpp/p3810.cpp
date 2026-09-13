#include<bits/stdc++.h>
using namespace std;
const int maxn=114514;
int n,m=1,c,sum[maxn<<1],t[maxn];
class node{
    public:
    int a,b,c,siz,ans;
    inline bool operator<(const node&nxt)const{
        if(a!=nxt.a) return a<nxt.a;
        else if(b!=nxt.b) return b<nxt.b;
        else return c<nxt.c;
    }
}a[maxn],dig[maxn];
inline int lowbit(int x){
    return -x&x;
}
inline void update(int i,int x){
    if(!i)return;
    for(;i<=c;i+=lowbit(i)) t[i]+=x;
}
inline int query(int i){
    int ret=0;
    for(;i;i-=lowbit(i)) ret+=t[i];
    return ret;
}
inline void CDQ(int L,int R){
    if(L==R) return;
    int M=(L+R)>>1;
    CDQ(L,M);
    CDQ(M+1,R);
    int l=L,r=M+1,cnt=L;
    while(l<=M&&r<=R){
        if(a[l].b<=a[r].b) update(a[l].c,a[l].siz),dig[cnt++]=a[l++];
        else a[r].ans+=query(a[r].c),dig[cnt++]=a[r++];
    }
    while(l<=M) update(a[l].c,a[l].siz),dig[cnt++]=a[l++];
    while(r<=R) a[r].ans+=query(a[r].c),dig[cnt++]=a[r++];
    for(int i=L;i<=M;i++) update(a[i].c,-a[i].siz);
    for(int i=L;i<=R;i++) a[i]=dig[i];
}
signed main(){
    scanf("%d %d",&n,&c);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&a[i].a,&a[i].b,&a[i].c);
        a[i].ans=0;a[i].siz=1;
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        if(a[i].a==a[m].a&&a[i].b==a[m].b&&a[i].c==a[m].c) a[m].siz++;
        else a[++m]=a[i];
    }
    CDQ(1,m);
    for(int i=1;i<=m;i++){
        // printf("%d %d %d\n",i,a[i].ans,a[i].siz);
        sum[a[i].ans+a[i].siz-1]+=a[i].siz;
    }
    for(int i=0;i<n;i++) printf("%d\n",sum[i]);
    system("pause");
    return 0;
}
/*
10 3
3 3 3
2 3 3
2 3 1
3 1 1
3 1 2
1 3 1
1 1 2
1 2 2
1 3 2
1 2 1
3
1
3
0
1
0
1
0
0
1
*/
