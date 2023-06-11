#include <bits/stdc++.h>
using namespace std;
long long fastexp(int a, long long n, int p){
    long long res = 1;
    a = a%p;
    while(n>0){
        if(n&1) res = (1LL*res*a)%p;
        n = n>>1;
        a = (1LL*a*a)%p;
    }
    return res;
}
long long invmod(int a, int p){
    return fastexp(a,p-2,p)%p;
}
int main(){
    int t;
    ifstream cin("hawawshi.in");
    cin >> t;
    while(t--){
        int n, x, A, B, a, b, p;
        cin >> n >> x >> A >> B >> a >> b >> p;
        int answ = 0;
        if(a == 1){
            for(int i=A; i<=B; i++){
                int aux = ((x-i+p)%p*invmod(b,p))%p;
                if(aux < n){
                    answ++;
                }
            }
        } 
        else{
            int aux = floor(sqrt(1.0*p));
            unordered_map <long long,int> pota;
            long long wath[aux+1];
            wath[0] = 1;
            long long an = fastexp(a,aux,p)%p;
            long long pox = an;
            for(int i=1; i<=aux; i++){
                if(!pota[pox]){
                    pota[pox] = aux*i;
                }
                pox = (pox*an)%p;
            }
            long long wa = (1LL*b*invmod(a-1,p)%p)%p;
            for(int i=A; i<=B; i++){
                long long d = (x+wa)%p;
                d = (1LL*d*fastexp(i+wa,p-2,p)%p)%p;
                if(i == (1LL*b*fastexp(1-a+p,p-2,p))%p){
                    if(i == x){
                        answ++;
                    }
                }
                else{
                    long long cur = d;
                    for(int j=0; j<=aux; j++){
                        int r = pota[cur];
                        int gg = r-j;
                        if(r == 0){
                            if(gg==0 and d == 1){
                                answ++;
                                break;
                            }
                            else{
                                cur = (1LL*cur*a)%p;
                                continue;
                            }
                        }
                        if(gg >= n){
                            cur = (1LL*cur*a)%p;
                            continue;
                        }
                        answ++;
                        break;
                    }
                }
            }    
        }
        int gc = __gcd(answ,B-A+1);
        cout << answ/gc << "/"<< (B-A+1)/gc << '\n'; 
    }
    return 0;
}
