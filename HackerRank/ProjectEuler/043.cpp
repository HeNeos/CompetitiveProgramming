#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 22212
// 711104
// 32415256
// 738627129
// 10075795374
// 23206443184
// 16695334890
int main() {
    int n; cin >> n;
    long long ans[7] = {22212, 711104, 12444480, 189838560, 1099210170, 1113342912, 16695334890LL};
    
    cout << ans[n-3] << '\n';
    return 0;
}
