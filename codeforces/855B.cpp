#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, p, q, r;
	cin >> n >> p >> q >> r;
	int arr[n];
	for(int i=0; i<n; i++) cin >> arr[i];
	int maxx[n];
	int minn[n];
	for(int i=n-1; i>=0; i--){
		maxx[i] = -1000000005;
		minn[i] = 1000000005;
	}
	maxx[n-1] = arr[n-1];
	minn[n-1] = arr[n-1];
	for(int i=n-2; i>=0; i--){
		maxx[i] = max(maxx[i+1],arr[i]);
		minn[i] = min(minn[i+1],arr[i]);
	}
	long long dp[n];
	int posq = n-1;
	dp[n-1] = 1LL*p*arr[n-1]+1LL*q*arr[n-1]+1LL*r*arr[n-1];
	for(int i=n-2; i>=0; i--){
		long long aux = dp[i+1] - 1LL*p*arr[i+1] + 1LL*p*arr[i];
		long long aux4;
		if(r >= 0) aux4 = aux-1LL*q*arr[posq]-1LL*r*maxx[posq]+1LL*q*arr[i]+1LL*r*maxx[i];
		else aux4 = aux-1LL*q*arr[posq]-1LL*r*minn[posq]+1LL*q*arr[i]+1LL*r*minn[i];
		long long maxi = max(aux,aux4);
		dp[i] = maxi;
		if(aux4 == maxi){
			posq = i;
		}
	}
	long long answ = dp[0];
	for(int i=0; i<n; i++) answ = max(answ,dp[i]);
	cout << answ << '\n';
	return 0;
}
