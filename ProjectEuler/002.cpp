#include <iostream>
#include <vector>
using namespace std;
#define N 4000000
vector <int> f;
void build(){
    f.push_back(1);
    f.push_back(2);
    int a = 1;
    int b = 2;
    for(;;){
        b = a+b;
        a = b-a;
        if(b > N) break;
        f.push_back(b);
    }
}

int main(){
    build();
    int ans = 0;
    for(int i=0; i<f.size(); i++)
        ans += (1 - f[i]&1)*f[i];
    cout << ans << '\n';
    return 0;
}