#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int k;
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		if(5*i*(i + 1) <= 2*(240 - k)) continue;
		else{
			cout<<i - 1;
			return 0;
		}
	}
	cout<<n;
	return 0;
}
