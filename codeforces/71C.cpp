#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	vector <int> divis;
	cin >> n;
	if(n>=3) divis.push_back(1);
	if(n>=6){
	  if(n%2 == 0) divis.push_back(2);
	}
	for(int i=3; i*i<=n; i++){
		if(n%i==0){
		  divis.push_back(i);
		  if(n/i * n/i == n) continue;
		  divis.push_back(n/i);
		}
	}
	int knights[n];
	for(int i=0; i<n; i++){
		cin >> knights[i];
	}
	for(int i=0; i<divis.size(); i++){
		for(int j=0; j<divis[i]; j++){
			for(int k=j; k<n; k = k+divis[i]){
				if(knights[k] == 0) break;
				if(k+divis[i] >= n){
					cout << "YES";
					return 0;
				}
			}
		}
	}
	cout << "NO";
	return 0;
}
