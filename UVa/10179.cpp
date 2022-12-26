#include <bits/stdc++.h>
using namespace std;

vector <int> getPrimeFactors(int n){
    vector <int> ans;
    for(int i=2; 1LL*i*i<=n; i++){
        if(n%i == 0){
            while(n%i == 0)
                n /= i;
            ans.push_back(i);
        }
    }
    if(n != 1) ans.push_back(n);
    return ans;
}

int eulerTotient(int n, vector <int> &primeFactors){
    for(auto primeFactor : primeFactors){
        n /= primeFactor;
        n *= (primeFactor - 1);
    }
    return n;
}

int main(){
    int n;
    while(cin >> n){
        if(n == 0) break;
        vector <int> primeFactors = getPrimeFactors(n);
        cout << eulerTotient(n, primeFactors) << '\n';
    }
    return 0;
}