#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector <long long> arr;
	while(n--){
		long long a;
		cin >> a;
		arr.push_back(a);
	}
	long long answ = 0;
	for(int i=1; i<=arr.size(); i++){
		if(arr[i-1] == 1) answ += 1LL;
		else answ += 1LL*i*(arr[i-1]-2) + (1+i);
	}
	cout << answ;
	return 0;
}
