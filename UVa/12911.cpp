/*
*
* Meet in the middle is fun! :v
*
*/
#include <bits/stdc++.h>
using namespace std;
long long slve(int N, vector <long long> nmb, long long S){
	vector <long long> div1(N/2);
	vector <long long> div2((N+1)/2);
	vector <long long> sum1;
	vector <long long> sum2;
	for(int i=0; i<N/2; i++) div1[i] = nmb[i];
	for(int i=0; i<(N+1)/2; i++) div2[i] = nmb[N/2 + i];
	int mask1 = (1<<(N/2));
	int mask2 = (1<<((N+1)/2));
	for(int i=0; i<mask1; i++){
		long long sum = 0;
		for(int k=0; k<N/2; k++){
			if(i&(1<<k)) sum += div1[k];
		}
		sum1.push_back(sum);
	}
	for(int i=0; i<mask2; i++){
		long long sum = 0;
		for(int k=0; k< (N+1)/2; k++){
			if(i&(1<<k)) sum += div2[k];  
		}
		sum2.push_back(sum);
	}
	int aux = sum2[0];
	sort(sum2.begin(), sum2.end());
	long long answ = 0;
	for(int i=0; i<sum1.size(); i++){
		auto lo = lower_bound(sum2.begin(), sum2.end(),1LL*S-sum1[i]);
		auto hi = upper_bound(sum2.begin(), sum2.end(),1LL*S-sum1[i]);
		if(lo-sum2.begin() != sum2.size()) answ += ((hi - sum2.begin()) - (lo-sum2.begin()));
	}
	if(sum1[0] + aux == S) answ--;
	return answ;
	
}
int main(){
	int N;
	long long T;
	while(scanf("%d %lld", &N, &T) == 2){
		vector <long long> numbs(N);
		for(int i=0; i<N; i++) cin >> numbs[i];
		cout << slve(N, numbs , T) << '\n';
	}
	return 0;
}
