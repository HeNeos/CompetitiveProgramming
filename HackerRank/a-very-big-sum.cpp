#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long sum = 0;
    for(int i=1; i<=n; i++){
        long long a;
        cin >> a;
        sum += a;
    }
    cout << sum;
    return 0;
}
