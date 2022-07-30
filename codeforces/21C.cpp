#include <bits/stdc++.h>
using namespace std;
vector <long long> numb;
vector <long long> posx;
vector <long long> posy;
long long cont = 0;
int main(){
    long long n;
    long long sum = 0;
    cin >> n;
    while(n--){
        long long a;
        cin >> a;
        numb.push_back(a);
        sum += a;
    }
    if(abs(sum-0)%3 != 0 || numb.size()<3){
        cout << 0;
        return 0;
    }
    long long aux = 0;
    for(int i=0; i<numb.size(); i++){
        aux += numb[i];
        if(aux == sum/3){
            posx.push_back(i);
        }
        if(aux == 2*sum/3){
            posy.push_back(i);
        }
    }
    for(int i=0; i<posx.size(); i++){
        int low = 0;
        int high = posy.size()-1;
        while(low<high){
            int med = low + (high-low)/2;
            if(posx[i] < posy[med]) high = med;
            else low = med+1;
        }
        if(posy[low] < posx[i]) continue;
        cont += posy.size()-low;
        if(posy[posy.size()-1] == numb.size()-1) cont--;
    }
    cout << cont;
    return 0;
}
