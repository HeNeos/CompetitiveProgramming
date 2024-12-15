#include <iostream>
using namespace std;

int solve(int x){
    return x*(x+1)/2;
}

int main(){
    int ans = 3*solve(999/3) + 5*solve(999/5) - 15*solve(999/15);
    cout << ans << '\n';
    return 0;
}