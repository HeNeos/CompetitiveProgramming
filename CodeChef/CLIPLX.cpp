#include <iostream>
using namespace std;
int main() {
    int test;
    cin>>test;
    for(int i=1; i<=test; i++){
        int X;
        int Y;
        cin>>X>>Y;
        if(Y>=X) cout<<0<<"\n";
        else cout<<X-Y<<"\n";
    }
    return 0;
}
