#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int N;
    while(cin >> N){
        long double aux = log(N)/log(18);
        long double lo = floorl(aux);
        if (aux - lo < 0.00000001){
            cout << "Ollie wins.\n";
            continue;
        }
        if (N/powl(18.0,lo) > 9.0) cout << "Ollie wins.\n";
        else cout << "Stan wins.\n";
    }
    return 0;
}
