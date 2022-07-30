#include <iostream>
using namespace std;

int main() {
	long long n;
	long long m;
	long long a;
	cin >> n >> m >> a;
	long long leng=n/a;
	long long heig=m/a;
	if(1LL*leng*heig*a*a==1LL*m*n) cout<<1LL*leng*heig;
	else{
		if(n%a != 0 && m%a !=0) cout<<1LL*leng*heig+leng+heig+1;
		if(m%a==0) cout<<1LL*leng*heig+heig;
		if(n%a==0) cout<<1LL*leng*heig+leng;
	}
	return 0;
}
