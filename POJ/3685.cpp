/*
*
*
* First Solution: Binary Search
*
*
*/

#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
long long value(long long row, long long column){
	long long val = 1LL*row*row + 100000LL*row + 1LL*column*column - 100000LL*column + 1LL*row*column;
	return val;
}
int main() {
	int tests;
	cin >> tests;
	while(tests--){
		long long n;
		long long m;
		long long seclo;
		long long countm1 = 0;
		cin >> n >> m;
		if(n > 50000) seclo = -2500000000;
		else seclo = 1+100000+n*n-100000*n+n;
		long long sechi = max(n*n+100000*n+1-100000+n,3*n*n);
		while(sechi>seclo){
			countm1 = 0;
			long long m1 = seclo + (sechi - seclo)/2;
			for(long long j=1; j<=n; j++){
				long long him1 = n+1;
				long long lom1 = 1;
				while(lom1<him1){
					long long mem1 = lom1 + (him1 - lom1)/2;
					if(value(mem1,j)>=m1) him1 = mem1;
					else lom1 = mem1 + 1;
					if(m1==value(mem1,j)) countm1++;
				}
				countm1 += lom1 - 1;
			}
			if(countm1>=m){
				sechi=m1;
			}
			else seclo=m1+1;
		}
		 printf("%lld\n", seclo);
	}
	return 0;
}


/*
*
*
* Second Solution: Ternary Search | TLE
*
* With the ternary search on the answer, admit that there is a first area
* where the numbers are too small to meet the condition of the problem,
* a second zone where the numbers meet the condition and a third where they surpass it.
* Note that the minor element of the second zone is the element that you want to find and that belongs to the matrix.
*
*
*/
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
long long value(long long row, long long column){
	long long val = row*row + 100000*row + column*column - 100000*column + row*column;
	return val;
}
int main() {
	int tests;
	cin >> tests;
	while(tests--){
		long long n;
		long long m;
		long long seclo;
		long long countm1 = 0;
		long long countm2 = 0;
		cin >> n >> m;
		if(n > 50000) seclo = -2500000000;
		else seclo = 1+100000+n*n-100000*n+n;
		long long sechi = max(n*n+100000*n+1-100000+n,3*n*n);
		while(sechi>seclo || countm1 != countm2){
			countm1 = 0;
			countm2 = 0;
			long long m1 = seclo + (sechi - seclo +2)/3;
			long long m2 = sechi - (sechi - seclo)/3;
			for(long long j=1; j<=n; j++){
				long long him1 = n+1;
				long long lom1 = 0;
				while(lom1<him1){
					long long mem1 = lom1 + (him1 - lom1)/2;
					if(value(mem1,j)>=m1) him1 = mem1;
					else lom1 = mem1 + 1;
				}
				if(lom1==0) countm1++;
				countm1 += lom1 - 1;
			}
			for(long long j=1; j<=n; j++){
				long long him2 = n+1;
				long long lom2 = 0;
				while(lom2<him2){
					long long mem2 = lom2 + (him2 - lom2)/2;
					if(value(mem2,j)>=m2) him2 = mem2;
					else lom2 = mem2 + 1;
				}
				if(lom2==0) countm2++;
				countm2 += lom2 - 1;
			}
			if(countm1 == m && countm2 == m){
				sechi = m2-1;
				continue;
			}
			if(countm1 == m && countm2 > m){
				sechi = m2 - 1;
				continue;
			}
			if(countm1 > m && countm2 > m){
				sechi = m2 - 1;
				continue;
			} 
			if(countm1 < m && countm2 <= m){
				seclo = m1;
				continue;
			}
			if(countm1 < m && countm2 > m){
				sechi = m2 - 1;
				continue;
			}
		}
		 printf("%lld\n", seclo);
	}
	return 0;
}
