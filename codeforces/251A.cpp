#include <bits/stdc++.h>
using namespace std;
int n;
int d;
int main(){
    cin >> n >> d;
    int a[n+1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long answ = 0;
    for (int i = 1; i <= n - 2; i++){
        int pos = upper_bound(a + 1, a+n+1, a[i] + d) - a;
        long long dif = pos - i - 1;
        if (dif >= 1) answ += (dif * (dif - 1) / 2);
        }
    cout << answ << endl;
    return 0;
}
