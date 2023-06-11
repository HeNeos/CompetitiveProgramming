#include <bits/stdc++.h>
using namespace std;
long long bitcount(long long n){
    long long i;
    long long j=n;
    int cnt=0;
    while(j!=0){
        cnt++;
        j/=2;
    }
    return cnt;
}
int main() {
    int test;
    cin >> test;
    for(int i=1; i<=test; i++){
        long long A;
        long long B;
        cin >> A >> B;
        int bitsB=bitcount(B);
        int bitsA=bitcount(A);
        cout<<"Case "<<i<<": ";
        if(bitsB>bitsA) cout << (1LL<<bitsB)-1 << " " << 0;
        else{
            int contbits = 0;
            for(int k=1; k<=bitsB; k++){
                if(!(((B>>(bitsB-k))&1)^((A>>(bitsB-k))&1))) contbits++;
                else break;
            }
            long long ansand = (((1LL*B)>>(bitsB-contbits))<<(bitsB-contbits));
            long long ansor = ansand + (1LL<<(bitsB-contbits))-1;
            cout << ansor << " " << ansand;
        }
        cout<<"\n";
    }
        return 0;
}
