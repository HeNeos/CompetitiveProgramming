#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[6] = {0,1,2,3,4,5};
    int numb[6];
    for(int i=0; i<6; i++) cin >> numb[i];
    do{
        long long sum1 = numb[arr[0]] + numb[arr[1]] + numb[arr[2]];
        long long sum2 = numb[arr[3]] + numb[arr[4]] + numb[arr[5]];
        if(sum1 == sum2){
            cout << "YES";
            return 0;
        }
    }while(next_permutation(arr,arr+6));
    cout << "NO";
    return 0;
}
