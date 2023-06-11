/*
*
* 2242:The Circumference of the Circle
* http://poj.org/problem?id=2242
*
*/
#include<iostream>
#include<cmath>
#include<cstdio>
#define pi 3.141592653589793
using namespace std;
double distancia(double a1, double b1, double a2, double b2){
    double dist=sqrt((a1-a2)*(a1-a2)+(b1-b2)*(b1-b2));
    return dist;
}
double x1;
double x2;
double x3;
double z1;
double z2;
double z3;
int main(){
    while(cin>>x1>>z1>>x2>>z2>>x3>>z3){
        double l1=distancia(x1,z1,x2,z2);
        double l2=distancia(x1,z1,x3,z3);
        double l3=distancia(x2,z2,x3,z3);
        double semp=(l1+l2+l3)/2;
        double area=sqrt(semp*(semp-l1)*(semp-l2)*(semp-l3));
        double R=2*pi*(l1*l2*l3)/(area*4);
        printf("%.2lf\n",R);
    }
        return 0;
}
