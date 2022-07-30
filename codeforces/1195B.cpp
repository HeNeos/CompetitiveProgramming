#include <bits/stdc++.h>
using namespace std;
int main(){
        int n, k;
        cin >> n >> k;
        for(long long i=floor(sqrt(2LL*k+2LL*n)); i>0; i--){
                if(1LL*i*i + 1LL*3*i  == 1LL*2*(k+n)) cout << n - i;
        }
        return 0;
}
