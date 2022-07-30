#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		int p1;
		int p2;
		int q1;
		int q2;
		cin >> p1 >> p2 >> q1 >> q2;
		cout << 2*q1-p1 << " " << 2*q2-p2 << "\n";
	}
	return 0;
}
