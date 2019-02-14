#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin>>N;
	vector <int> arr(N);
	for(int i=0; i<N; i++){
		cin>>arr[i];
	}
	for(int mask=0; mask<(1<<N); mask++){
		int sumx=0;
		int sumy=0;
		for(int bit=0; bit<N; bit++){
			if((mask>>bit) & 1) sumx=sumx+arr[bit];
			else sumy=sumy+arr[bit];
		}
		if((abs(sumx-sumy))%360==0){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
