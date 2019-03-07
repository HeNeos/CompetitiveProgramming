#include <bits/stdc++.h>
using namespace std;
int main(){
	int arr1[3];
	int answ1 = 0;
	int answ2 = 0;
	for(int i=0; i<3; i++) cin >> arr1[i];
	for(int i=0; i<3; i++){
		int a;
		cin >> a;
		if(arr1[i] > a) answ1++;
		if(a > arr1[i]) answ2++;
	}
	cout << answ1 << " " << answ2;
	return 0;
}
