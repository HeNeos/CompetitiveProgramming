#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	int number;
	int aux1 = INT_MAX;
	vector <int> minm;
	for(int i=0; i<n; i++){
		aux1 = INT_MAX;
		for(int j=0; j<m; j++){
			cin >> number;
			aux1 = min(aux1,number);
		}
		minm.push_back(aux1);
	}
	aux1 = -1;
	for(int i=0; i<minm.size(); i++) aux1 = max(aux1,minm[i]);
	cout << aux1;
	return 0;
}
