#include <bits/stdc++.h>
using namespace std;
vector <long long> price;
long long mon;
long long sum = 0;
long long answ2=0;
bool test(long long elm){
    sum = 0;
    long long npr[price.size()];
    for(int i=0; i<price.size(); i++){
        npr[i] = price[i];
    }
    for(int i=0; i<price.size(); i++){
        npr[i] = 1LL*npr[i] + 1LL*(i+1)*elm;
    }
    sort(npr, npr+price.size());
    for(long long i=0; i<elm; i++) sum += npr[i];
    if(sum <= mon){
        answ2 = sum;
        return true;
    }
    else return false;
}
int main() {
    long long n;
    cin >> n >> mon;
    for(long long i=0; i<n; i++){
        long long a;
        cin >> a;
        price.push_back(a);
    }
    long long low = 0;
    long long high = n;
    while(low < high){
        int med = low + (high - low + 1)/2;
        if(test(med)) low = med;
        else high = med -1;
    }
    cout << low << " " << 1LL*answ2;
    return 0;
}
