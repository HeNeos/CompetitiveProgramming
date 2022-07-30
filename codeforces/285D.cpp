#include <bits/stdc++.h>
using namespace std;
long long prim = 1000000007;
long long facto(int n){
	long long answ=1;
	if(n>=1){
		for(int i=2; i<=n; i++) answ = (answ*i)%prim;
		return answ;
	}
	else return 1;
}
int main() {
	int n;
	cin >> n;
	/*
	arr:
	https://oeis.org/A006717
	Number of ways of arranging 2n+1 nonattacking semi-queens on a (2n+1) X (2n+1) toroidal board.
	*/
	long long arr[]={1, 3, 15, 133, 2025, 37851, 1030367, 36362925, 1606008513, 87656896891};
	if(n % 2 == 0) cout<<0<<endl;
	else cout<<(facto(n)*(arr[n/2])%prim)%prim<<endl;
	return 0;
}
