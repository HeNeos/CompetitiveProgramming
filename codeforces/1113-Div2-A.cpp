#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int v;
	cin >> n >> v;
	if(v>=n-1) cout << n-1;
	else cout << v-1+((n-v)*(n-v+1))/2;
	return 0;
}
