/*
*
* INS17M - Fibonacci and Easy GCD
* https://www.spoj.com/problems/INS17M/
*
*
* Time complexity O(N^2*lg(k))<=O(10^11) :(
* This could be resolved with the Pisano period but I don't know how to implement it.
*/

#include<bits/stdc++.h>
using namespace std;
long long prim=1000000007;
long long K;
int N;
long long fstexpmod(long long n, long long k){
    if(k==1) return(n);
    if(k%2==0) return((fstexpmod(n,k/2)));
    else return((n*fstexpmod(n,k-1)));
}
long long fib(long long n){
    double phi=(1+sqrt(5))/2;
    return round((pow(phi,n)-pow((1-phi),n))/sqrt(5));
}
int main(){
    cin>>N>>K;
    int vfib[N];
    long long sum=0;
    for(int i=0;i<=N-1; i++){
        cin>>vfib[i];
    }
    for(int i=0; i<=N-2; i++){
        for(int j=i+1; j<=N-1; j++){
            long long ind=fstexpmod(__gcd(vfib[i],vfib[j]),K);
            sum=(sum+fib(ind))%prim;
        }
    }
    cout<<sum<<endl;
}
