#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    int cifr;
    cin>>n;
    cifr=floor(log10(n))+1;
    int i=0;
    while(i<cifr){
        if(n%10==1){
            n=n/10;
            i++;
            continue;
        }
        else{
            if(n%10==4){
                n=n/10;
                if(n%10==1){
                    n=n/10;
                    i=i+2;
                    continue;
                }
                else{
                    if(n%10==4){
                        n=n/10;
                        if(n%10==1){
                            n=n/10;
                            i=i+3;
                            continue;
                        }
                        else{
                            cout<<"NO";
                            return 0;
                        }
                    }
                }
            }
            else{
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
    return 0;
}
