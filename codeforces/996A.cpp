#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int din = 0;
    din += n/100;
    n %= 100;
    din += n/20;
    n %= 20;
    din += n/10;
    n %= 10;
    din += n/5;
    n %= 5;
    din += n/1;
    cout << din;
    return 0;
}
