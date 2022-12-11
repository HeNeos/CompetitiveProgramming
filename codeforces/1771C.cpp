#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 100005
bitset <N> primes;
vector <int> p;
void sieve(){
    for(int i=2; i<N; i++){
        if(!primes[i]){
            p.push_back(i);
            for(ll j=1LL*i*i; j<N; j+=i) primes[j] = 1;
        }
    }
}

int main(){
    sieve();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i=0; i<n; i++) cin >> arr[i];
        map <int, int> m;
        bool found = false;
        for(int i=0; i<n; i++){
            int current_value = arr[i];
            for(int j=0; j<p.size(); j++){
                int current_p = p[j];
                if(1LL*current_p*current_p > current_value) break;
                if(current_value%current_p == 0){
                    while(current_value%current_p == 0){
                        current_value /= current_p;
                    }
                    m[current_p]++;
                    if(m[current_p] >= 2){
                        found = true;
                        break;
                    }
                }
            }
            if(found) break;
            if(current_value != 1){
                m[current_value]++;
                if(m[current_value] >= 2){
                    found = true;
                    break;
                }
            }
        }
        if(found) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
    return 0;
}
