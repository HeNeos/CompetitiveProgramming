#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 300000000
bitset <N> B;
bitset <N> OB;

void build(){
    for(int i=0; i*i<N; i++){
        B[i*i] = 1;
        if(i%2) OB[i*i] = 1;
    }
}

int genNumber(vector <int> &d, int f){
    int v = 0;
    int sz = d.size();
    for(int i=0; i<sz; i++){
        v *= 10;
        v += d[i];
    }
    for(int i=sz-1-f; i>=0; i--){
        v *= 10;
        v += d[i];
    }
    return v;
}

void genPalindromes(int d, vector <int> &a){
    int sz = (d+1)/2;
    vector <int> digits(sz);
    digits[0] = 1;
    while(digits[sz-1] != 10){
        a.push_back(genNumber(digits, d%2));
        int p = 0;
        digits[p]++;
        while(digits[p] >= 10){
            p++;
            if(p == sz) break;
            digits[p-1] -= 10;
            digits[p]++;
        }
        if(digits[0] == 0) digits[0]++;
    }
}

// a^2*(2n+1) + (n)*(n+1)*(2n+1)/3

bool testOdd(int x){
    for(int i=1; i<400; i++){
        int v = x;
        ll aux = (1LL*i*(i+1)*(2*i+1))/3;
        if(aux >= v) return false;
        v -= aux;
        if(v%(2*i+1) == 0){
            v /= (2*i+1);
            if(B[v]){
                int sq = (int)(sqrt(v));
                return (sq - i > 0);
            }
        }
    }
    return false;
}

// a^2*(2n) + 2*(0.5^2 + 1.5^2 + ... + ((2n-1)/2)^2)
// a^2*(2n) + 2*(1^2+3^2+...+(2n-1)^2)/4
// ((2*k+1)/2)^2 = 4k2 + 4k + 1
// S = (2n*(2n+1)*(4n+1))/6
// ans = S - 4*(n*(n+1)*(2n+1))/6
// ans = ((2n+1)*(2n)*(2n-1))/6

bool testEven(int x){
    for(int i=1; i<400; i++){
        int v = 2*x;
        ll aux = ((4*i*i-1)*i)/3;
        if(aux >= v) return false;
        
        v -= aux;
        if(v%i == 0){
            v /= i;
            if(OB[v]){
                int sq = (int)(sqrt(v));
                return sq - 2*i > 0;
            }
        }
    }
    return false;
}

int main(){
    build();
    ll ans = 0;
    for(int d=1; d<=8; d++){
        vector <int> numbers;
        genPalindromes(d, numbers);
        for(int v : numbers){
        	bool t = testOdd(v);
            if(t){
                cout << "ODD " << v << endl;
                ans += v; 
            }
            else{
                t = testEven(v);
                if(t){
                    cout << "EVEN " << v << endl;
                    ans += v;
                }
            }
            
        }
    }
    cout << ans << '\n';
    return 0;
}
