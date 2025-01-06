#include <bits/stdc++.h>
using namespace std;
#define MAXN 2000000000000

using ll = unsigned long long;

int primes[15] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
vector <ll> values;

void generateValues(ll previous, int index){
  if(previous < MAXN) values.push_back(previous);
  else return;
  for(int i=index; i<15; i++){
    if(previous*primes[i] < MAXN)
      generateValues(previous*primes[i], i);
    else break;
  }
}

int main(){
  generateValues(1, 0);
  sort(values.begin(), values.end());
  ll ans = 0;
  for(int i=0; i<values.size()-1; i++){
    if(values[i] + 1 == values[i+1]){
      ans += values[i];
    }
  }
  cout << ans << '\n';
  return 0;
}
