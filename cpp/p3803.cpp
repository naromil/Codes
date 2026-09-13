#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const double pi=acos(-1.0);
class Complex{
	public: double a,b;
	Complex(double R=0,double I=0){ a=R; b=I; }
	Complex operator + (Complex v){ return Complex(a+v.a, b+v.b); }
	Complex operator - (Complex v){ return Complex(a-v.a, b-v.b); }
	Complex operator * (Complex v){ return Complex(a*v.a-b*v.b, a*v.b+b*v.a); }
};
vector<int> rp;
// void fft(int n,vector<Complex>& a,int op){
// 	if(n==1) return;
// 	vector<Complex> l(n>>1),r(n>>1);
// 	for(int i=0;i<n;++i){
// 		if(i&1) r[i>>1]=a[i];
// 		else l[i>>1]=a[i];
// 	}
// 	fft(n>>1,l,op);
// 	fft(n>>1,r,op);
// 	Complex w0=Complex(cos(2.0*pi/n),op*sin(2.0*pi/n)), w=Complex(1,0);
// 	for(int i=0;i<(n>>1);++i,w=w*w0){
// 		a[i]=l[i]+w*r[i];
// 		a[i+(n>>1)]=l[i]-w*r[i];
// 	}
// }
inline void fft(int n,vector<Complex>& a,int op){
    for(int i=0;i<n;++i) if(i<rp[i]) swap(a[i],a[rp[i]]);
    for(int m=1;m<n;m<<=1) for(int l=0;l<n;l+=(m<<1)){
        Complex w0=Complex(cos(pi/m),op*sin(pi/m)), w=Complex(1,0);
        for(int i=l;i<l+m;++i,w=w*w0){
            Complex L=a[i], R=w*a[i+m];
            a[i]=L+R;
            a[i+m]=L-R;
        }
    }
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int N,M; cin>>N>>M;
	int n=1<<(int)ceil(log2(N+M+1));
	rp.resize(n);
	for(int i=0;i<n;++i){
        rp[i]=(rp[i>>1]>>1)|((i&1)*(n>>1));
	}
	vector<Complex> a(n),b(n);
	for(int i=0;i<=N;++i){ cin>>a[i].a; }
	for(int i=0;i<=M;++i){ cin>>b[i].a; }
	fft(n,a,1);
	fft(n,b,1);
	for(int i=0;i<n;++i) a[i]=a[i]*b[i];
	fft(n,a,-1);
	for(int i=0;i<N+M+1;++i) printf("%d ",(int)round(a[i].a/n));
	printf("\n");
	return 0;
}
