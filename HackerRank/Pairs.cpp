#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
  int k;
	vector <int> arr;
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		int a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	long long answ=0;
	for(int i=0; i<n; i++){
		int low=i;
		int high=n-1;
		while(low<high){
			int med=low+(high-low)/2;
			if(arr[med]-arr[i] >= k) high=med;
			else low=med+1;

		}
		if(arr[low]-k==arr[i]) answ++;
	}
	cout << answ;
	return 0;
}
