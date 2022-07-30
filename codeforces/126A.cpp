#include<bits/stdc++.h>
using namespace std;
double tmaxmin=1<<20;
long long t1;
long long t2;
long long t0;
double T;
long long x1;
long long x2;
long long solx1;
long long solx2;
int main(){
	cin>>t1>>t2>>x1>>x2>>t0;
	while(x1>=0 && x2>=0){
		T=(1.0*t1*x1+t2*x2)/(x1+x2);
		if(T<t0){
			x1--;
		}
		else{
			if(T<tmaxmin){
				tmaxmin=T;
				solx2=x2;
				solx1=x1;
			}
			x2--;
		}
	}
	cout<<solx1<<" "<<solx2<<endl;
}
