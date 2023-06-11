#include <iostream>
#include <stdlib.h>
using namespace std;
int n;
long double A;
int i;
bool test(double numb){
    if(1.0*(i-1)*numb - 1.0*(i-2)*A + 1.0*(i-2)*(i-1) >= 0) return true;
    else return false;
}
/*
H1=A
H2=k'
H3=2k'+2-A
H4=3k'+6-2A
H5=4k'+12-3A
H6=5k'+20-4A
...
Hn=(n-1)k'+(n-1)*(n-2)-(n-2)*A
*/
int main(){
    cin >> n >> A;
    double hi = A;
    double lo = 0;
    for(int k = 1; k <= 80; k++){
        int cont = 0;
        double me = lo + (hi - lo)/2;
        for(i = 3; i <= n; i++){
            if(test(me)) cont++;
            else break;
        }
        if(cont == n-2) hi = me;
        else lo = me;
    }
    printf("%.2Lf",1.0*hi*(n - 1) - 1.0*(n-2)*A + 1.0*(n-2)*(n - 1));
    return 0;
}
