#include<bits/stdc++.h>
using namespace std;
int main(){
	long long low;
	long long high;
	cin >> low >> high;
	if(high-low<2){
		cout<<-1; //If the condition is met then there are not enough numbers to show
		return 0;
	}
	if(low%2==0){
		//low is even, then low+1 is odd.
		//low and low+1 are coprimes because, 
		//there is no prime factor that is less than or equal to 1
		//low+1 and low+2 are coprimes and low and low+2 are even.
		cout<<low<<" "<<low+1<<" "<<low+2;
		return 0;
	}
	if(high-low>2){
		//As in the previous case, but we added one to low to make it even
		cout<<low+1<<" "<<low+2<<" "<<low+3;
		return 0;
	}
	cout<<-1;
	return 0;
}
