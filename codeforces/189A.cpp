#include <iostream>
#include <stdlib.h>
#define MAX(a1,a2,a3) max(a1,max(a2,a3))
using namespace std;
int n,a1,a2,a3,sum[4001];

int SUMC(int longt)
{
    if (longt == 0){
    return 0;}

    if (longt < 0 || (longt > 0 && longt < a1 && longt < a2 && longt < a3)){ 
    return -314159265;} /*En caso no fuera posible escribir "n" como una 
    combinacion lineal de "a", "b" y "c", mostramos un resultado incoherente*/

    if (!sum[longt]){ 
    sum[longt] = MAX(SUMC(longt-a1),SUMC(longt-a2),SUMC(longt-a3)) + 1;}

    return sum[longt];
}

int main()
{
    cin >> n >> a1 >> a2 >> a3;
    cout << SUMC(n) << endl;
}
