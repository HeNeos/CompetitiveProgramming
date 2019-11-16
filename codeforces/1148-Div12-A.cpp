#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    cout << 2LL*c + 2LL*min(a,b) + 1*(a!=b);
    return 0;
}
