#include <bits/stdc++.h>
using namespace std;

#define N 100005
int divisors[N];
void sieve(){
    for(int i=2; i<N; i++){
        for(int j=i; j<N; j+=i) divisors[j] += i;
    }
    for(int i=2; i<N; i++) divisors[i] += (1-i);
}

vector <int> abundant;
void fill(){
    for(int i=2; i<N; i++){
        if(divisors[i] > i) abundant.push_back(i);
    }
}

int main() {
    sieve();
    fill();
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        bool found = false;
        for(int i=0; i<abundant.size(); i++){
            int x = abundant[i];
            if(2*x > n) break;
            if(divisors[n-x] > n-x){
                found = true;
                break;
            }
        }
        if(found) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
