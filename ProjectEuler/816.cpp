#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 2000000
#define TRIM 250LL*250
#define MOD 50515093

vector <pair <ll, ll> > s(N);

void fill(){
    s[0].first = 290797;
    s[0].second = s[0].first*s[0].first;
    s[0].second %= MOD;
    for(int i=1; i<N; i++){
        s[i].first = (s[i-1].second * s[i-1].second)%MOD;
        s[i].second = (s[i].first * s[i].first)%MOD;
    }
    sort(s.begin(), s.end());
}

ll dist(pair <ll, ll> a, pair <ll, ll> b){
    return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

ll solve(vector <pair <ll, ll> > points){
    int sz = points.size();
    
    if(sz == 2) return dist(points[0], points[1]);
    if(sz == 3)
        return min(dist(points[0], points[1]), min(dist(points[1], points[2]), dist(points[0], points[2])));

    int mid = sz/2;
    ll dl = solve(vector<pair<ll, ll> > (points.begin(), points.begin()+mid));
    ll dr = solve(vector<pair<ll, ll> > (points.begin()+mid, points.end()));
    ll d = min(dl, dr);
    d = min(d, TRIM);

    vector <pair <ll, ll> > strip;
    for(int i=0; i<sz; i++){
        if((points[i].first - points[mid].first)*(points[i].first - points[mid].first) < d)
            strip.push_back(make_pair(points[i].second, points[i].first));
    }
    sort(strip.begin(), strip.end());
    for(int i=0; i<strip.size(); i++){
        for(int j=i+1; j<strip.size(); j++){
            if(strip[j].first - strip[i].first >= d) break;
            d = min(d, dist(strip[i], strip[j]));
        }
    }
    return d;
}

int main(){
    fill();
    ll ans = solve(s);
    cout << sqrt(ans) << " " << ans << '\n';
    return 0;
}