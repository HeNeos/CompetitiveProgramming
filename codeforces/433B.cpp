#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int arr[n];
	int ord[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
		ord[i] = arr[i];
	}
	sort(ord,ord+n);
	long long sum1[n+1];
	long long sum2[n+1];
	sum1[0] = 0; sum2[0] = 0;
	for(int i=1; i<=n; i++){
		sum1[i] = sum1[i-1] + arr[i-1];
		sum2[i] = sum2[i-1] + ord[i-1];
	}
	int m;
	cin >> m;
	while(m--){
		int c, l, r;
		cin >> c >> l >> r;
		l--; r--;
		if(c==1){
			cout << sum1[r+1]-sum1[l] << '\n';
		}
		else{
			cout << sum2[r+1]-sum2[l] << '\n';
		}
	}
	return 0;
}
