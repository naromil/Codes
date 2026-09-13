#include<bits/stdc++.h>
using namespace std;
using ll=long long;
double a,b,c,d;
signed main(){
	cin>>a>>b>>c>>d;
	for(double i=-100;i<=100;i+=0.001){
		double j=i+0.001;
		double y1=a*i*i*i+b*i*i+c*i+d;
		double y2=a*j*j*j+b*j*j+c*j+d;
		if(y1<=0&&y2>=0||y1>=0&&y2<=0) cout<<fixed<<setprecision(2)<<i<<' ';
	}
	return 0;
}
