#include <iostream>
#include <math.h>
using ll = long long;
using namespace std;
// (x-N/2)^2 + (y-N/2)^2 = (N/sqrt(2))^2
// (2x-N)^2 + (2y-N)^2 = 2N^2
ll eval(int x, int y, int N){
    return 1LL*(2*x-N)*(2*x-N) + 1LL*(2*y-N)*(2*y-N);
}

int solve(int N){
    double sq = sqrt((double)(2));
    int st = (int)(((double)N - N*sq)/2) - 1;
    int end = (int)(((double)N + N*sq)/2) + 1;
    int ans = 0;
    cout << st << " " << end << endl;
    for(int x=st; x<=end; x++){
        for(int y=st; y<=end; y++){
            if(eval(x, y, N) == 2*N) ans++;
        }
    }
    return ans;
}

int main(){
    cout << solve(10000);
    return 0;
}