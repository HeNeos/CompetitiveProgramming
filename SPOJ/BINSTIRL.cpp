/*
*
* https://www.spoj.com/problems/BINSTIRL/
* Binary Stirling Numbers
* Complexity: O(d)
*
* First solution: https://en.wikipedia.org/wiki/Stirling_numbers_of_the_second_kind
*
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
	int d;
	long long n;
	long long k;
	cin>>d;
	for(int i=1; i<=d; i++){
		cin>>n>>k;
		long long z=n-ceil((k+1)/2);
		long long w=floor((k-1)/2);
		cout<<!((n-k)&((k-1)>>1))<<endl;
	}
}


/*
*
* Second solution:
* By the corollary of Lucas's theorem it is possible to
* find parity in time O(d*lg n).
* But, this solution give WA.
*
* Another alternative is iterare over the comb
* but the complexity is O(max(n-m,m)*d) giving TLE.
*
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	int d;
	long long n;
	long long k;
	cin>>d;
	for(int i=1; i<=d; i++){
		cin>>n>>k;
		long long z=n-ceil((k+1)/2);
		long long w=floor((k-1)/2);
		bitset <32> bsetz(z);
		bitset <32> bsetw(w);
		for(int i=0; i<=31; i++){
			if(bsetz[i]==0 && bsetw[i]==1){
				cout<<0<<"\n";
				break;
			}
		}
		cout<<1<<"\n";
	}
}
