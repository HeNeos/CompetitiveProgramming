#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
typedef pair <int,int> pii;
typedef vector <pii> vii;

double dist(double x1, double x2, double y1, double y2){
    double ans = hypot(abs(x1-x2), abs(y1-y2));
    return ans;
}
#define INF 100000000
int main(){
    int n;
    cin >> n;
    vector <pair <pii, int> > points(n);
    
    for(int i=0; i<n; i++){
        cin >> points[i].first.first >> points[i].first.second;
        points[i].second = i;
    }

    sort(points.begin(), points.end());
    pair <double, pair<int,int> > ans;
    
    ans.first = dist(points[0].first.first, points[1].first.first, points[0].first.second, points[1].first.second);
    ans.second.first = 0;
    ans.second.second = 1;
    for(int i=2; i<n; i++){
        int x = points[i].first.first;
        int y = points[i].first.second;
        auto lo = lower_bound(points.begin(), points.end(), mp(mp((int)(x - ans.first - 0.5), -INF),-INF));
        int p = (lo-points.begin());
        for(p; p < i; p++){
            int x1 = points[p].first.first;
            int y1 = points[p].first.second;
            if(dist(x,x1,y,y1) < ans.first){
                ans.first= dist(x,x1,y,y1);
                ans.second.first = points[p].second;
                ans.second.second = points[i].second;
            }
        }
    }
    int a = min(ans.second.first, ans.second.second);
    int b = max(ans.second.second, ans.second.first);
    cout << a << " " << b << " ";
    cout << fixed << setprecision(6) << ans.first;
    return 0;
}