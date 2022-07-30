#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		bool m;
		cin >> m;
		if(m){
			cout << "HARD";
			return 0;
		}
	}
	cout << "EASY";
	return 0;
}
