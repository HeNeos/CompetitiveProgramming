#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
vector<long long> coffe;
bool test(long long i){
	long long sum=0;
	for(long long j=0;j<n;++j){
		sum += max(coffe[j]-j/i,0LL);
	}
	if(sum>=m) return true;
	else return false;
}
int main(){
	cin>>n>>m;
	for(long long i=0;i<n;++i){
	    long long ccc;
	    cin >> ccc;
	    coffe.push_back(ccc);
	}
	sort(coffe.rbegin(),coffe.rend());
	long long low=1;
	long long high=n;
	while(low<high){
		long long me = low + (high-low)/2;
		if(test(me)) high=me;
		else low = me+1;	
	}
	if(test(low)) cout<<low<<endl;
	else cout<<-1<<endl;
	return 0;
}
