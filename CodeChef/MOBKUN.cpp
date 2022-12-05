// 1 = N 
// 2 = 2N
// 3 = 3N
// ...
// K-1 = (K-1)N
// K = KN + M
// K+1 = (K+1)N + M

// A = A*N + M*(A/K)
// (A-1)*N + M*((A-1)/K) < X <= A*N + M*(A/K)

// A = K*p+q
// if q >= 1
// (A-1)*N*K + M*(A-q) < X*K <= A*N*K + M*(A-q)
// A*(N*K + M) - (N*K - M*A%k) < X*K <= A*(N*K + M) - M*A%K
// if q = 0
// (A-1)*N*K + M*(A-K) < X*K <= A*N*K + M*(A)
// A*(N*K + M) - K*(N+M) < X*K <= A*(N*K + M)

#include <iostream>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, m, k, x;
        cin >> n >> m >> k >> x;
        long long val = 1LL*x*k;
        val = (val + 1LL*n*k + m - 1)/(1LL*n*k + m);
        val = (val+(k-1))/k; val *= k;
        if(x <= val*n + val/k * m && x > (val-1)*n + m*((val-1)/k)) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
    return 0;
}
