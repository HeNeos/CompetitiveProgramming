#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int sum1=0;
	int sum2=0;
	cin >> n;
	for(int j=1; j<=n; j++){
		for(int i=1; i<=n; i++){
			int a;
			cin >> a;
			if(i==j) sum1 += a;
			if(i==n-(j-1)) sum2 += a;
		}
	}
	cout << abs(sum1-sum2);
	return 0;
}
