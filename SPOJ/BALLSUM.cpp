#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main(){
    int N, K;
    while(true){
        cin >> N >> K;
        if(N == -1 and K == -1) break;
        if(K < 3){
            cout << "0\n";
            continue;
        }
        unsigned long long num = 0;
        if(K%2 == 0) num = (1LL * (K-2)/2 * ((K-2)/2 + 1));
        else num = (1LL * K-1)/2 * (K-1)/2;
        unsigned long long den = 1LL*N*(N-1)/2;
        unsigned long long g = __gcd(num, den);
        num /= g; den /= g;
        if(num == 0) cout << "0\n";
        else{
            if(num == den) cout << "1\n";
            else cout << num << "/" << den << '\n';  
        }
    }
    return 0;
}