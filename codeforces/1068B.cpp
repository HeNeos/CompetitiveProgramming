/*
*
* For two numbers b and a. Suppose that b=p*k and a=p*r
* gcd(b,a)=p and lcm(b,a)=p*k*r then lcm(a,b)*gcd(a,b)=a*b
* If a and b are coprimes then p=1.
* 
* For the problem, lcm(a,b)/a=b/gcd(a,b)
* Then, we could iterate to over b, instead of iterating over a
* But, the complexity is O(b)=O(10^10).
* However, we can notice that the answer is the quantity of numbers differents
* for b/gcd(a,b). b/gcd(a,b) is a integer, then the quantity of b/gcd(a,b) is the quantity of
* numbers differents for gcd(a,b). This is, the quantity of divisors of b.
* Then the complexity is O(sqrt(b))=O(10^5)
*
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
      long long b;
      cin>>b;
      int contdiv=0;
      for(long long i=1; i*i<=b; i++){
            if(b%i==0){
                  contdiv+=2;
            }
      }
      //Verify if the number is a perfect square.
      if(floor(sqrt(b))*floor(sqrt(b))==b) contdiv-=1;
      cout<<contdiv;
      return 0;
}
