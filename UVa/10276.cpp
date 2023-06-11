#include <iostream>
using namespace std;
int solver(int n){
    if(n==1) return 1;
    if(n==2) return 3;
    if(n%2==0) return solver(n-1)+n;
    else return solver(n-1)+n+1;
}
int main() {
    int test;
    cin >> test;
    for(int i=1; i<=test; i++){
        int numb;
        cin >> numb;
        cout << solver(numb);
        cout << "\n";
    }
    return 0;
}
