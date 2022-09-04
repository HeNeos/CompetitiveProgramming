#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int i=0; i<n; i++) cin >> a[i];
        sort(a, a+n);
        int firstCount = 0; int secondCount = 0;
        int firstValue = -1; int secondValue = -1;
        firstCount++;
        firstValue = a[0];
        int ans = 1;
        for(int i=1; i<n; i++){
            if(a[i] - firstValue <= 1){
                if(a[i] != firstValue){
                    secondValue = a[i];
                    secondCount++;
                }
                else
                    firstCount++;
            }
            else{
                if(secondValue == -1 or a[i] - secondValue > 1){
                    firstValue = -1; firstCount = 0;
                    secondValue = -1; secondCount = 0;
                    firstValue = a[i];
                    firstCount++;
                }
                else{
                    firstValue = secondValue;
                    firstCount = secondCount;
                    secondValue = a[i];
                    secondCount = 1;
                }
            }
            ans = max(ans, firstCount + secondCount);
        }
        cout << ans << '\n';
    }
    return 0;
}