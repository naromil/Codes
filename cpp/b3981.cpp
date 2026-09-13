#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
int n;
stack<int> vec;
inline void print(int x){
	putchar('(');
	if(x == 0){
		putchar('+');
		putchar('!');
		putchar('[');
		putchar(']');
	}
	else while(x--){
		putchar('+');
		putchar('!');
		putchar('!');
		putchar('[');
		putchar(']');
	}
	putchar(')');
}
signed main(){
	cin >> n;
	if(n == 0) vec.push(0);
	while(n > 0){
		vec.push(n % 10);
		n /= 10;
	}
	putchar('+'); putchar('('); putchar('(');
	print(vec.top()); vec.pop();
	putchar('+'); putchar('['); putchar(']'); putchar(')');
	while(!vec.empty()){
		putchar('+');
		print(vec.top()); vec.pop();
	}
	putchar(')');
	putchar('\n');
	return 0;
}
