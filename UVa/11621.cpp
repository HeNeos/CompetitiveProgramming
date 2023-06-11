#include <bits/stdc++.h>
using namespace std;
long long expo(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0) return 1LL*expo(a,b/2)*expo(a,b/2);
    else return 1LL*expo(a,1)*expo(a,(b-1));
}
int main(){
    vector <long long> numbers;
    for(int i=0; i<=32; i++){
        for(int j=0; j<=25; j++){
            //long long num = pow(2,i)*pow(3,j);
            long long num = 1LL*expo(2,i)*expo(3,j);
            if(num <= (1LL<<32)) numbers.push_back(num);
            else break;
        }
    }
    sort(numbers.begin(), numbers.end());
    while(true){
        long long m;
        cin >> m;
        if(m==0) break;
        cout << *lower_bound(numbers.begin(), numbers.end(), m) << "\n";
    }
    return 0;
}
