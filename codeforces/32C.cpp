/*
*
* C.Flea
*
* Let's analyze first as if it were a one-dimensional array. 
* If there is a position with which we can mark the maximum number of squares,
* it must necessarily be the first position, say to [1]. 
* Then from this position we will mark [1], a[1+s], a[1+2s], ..., a[1+k*s]. Where 1+k*s<=n.
* Now, note that starting at 1 is the same as starting at 1+s,since we can go back, 
* the same applies for the k+1 positions found
* this means that for each position that we find between 1 and 1+s such that we can mark k+1 positions,
* for each of them there will be other possible k+1 solutions.
* Then, for a row there are (k+1)*z solutions, where z represents the quantity of numbers
* between 1 and 1+s that can mark k+1 positions. 
* To perform this procedure quickly, we find the maximum value of k as k = floor((n-1)/s), then z=n-(1+k*s)+1. 
* Similarly for the columns, 1+p*s<=m. And let's say that there are d numbers that meet p+1 solutions. d=m-(1+p*s)+1. 
*
* The total number of solutions is d*z*(k+1)*(p+1).
*
* Complexity: O(1).
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int m;
	int s;
	int contf;
	int contc;
	cin>>n>>m>>s;
	int k;
	int p;
	k=(n-1)/s;
	p=(m-1)/s;
	contf=n-(1+k*s);
	contc=m-(1+p*s);
	cout<<1LL*(contf+1)*(k+1)*(p+1)*(contc+1);
	return 0;
}
