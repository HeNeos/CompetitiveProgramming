#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int div = 0;
	for(int i=1; i*i<=n; i++){
		if(!(n%i)) div += 2;
	}
	if(floor(sqrt(n))*floor(sqrt(n)) == n) div--;
	cout << div-1;
	return 0;
}
