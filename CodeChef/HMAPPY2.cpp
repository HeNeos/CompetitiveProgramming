#include <bits/stdc++.h>
using namespace std;
int main(){
	int test;
	cin>>test;
	for(int i=1; i<=test; i++){
		long long N;
		long long K;
		long long A;
		long long B;
		cin>>N>>A>>B>>K;
		int cont=(1LL*A*B)/(__gcd(A,B));
		int answ=N/cont;
		if(N/A+N/B-2*answ>=K) cout<<"Win\n";
		else cout<<"Lose\n";
	}
	return 0;
}
