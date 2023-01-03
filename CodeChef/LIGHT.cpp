#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> pdd; 
typedef pair<pdd, double> pddd;
typedef vector<pddd> vd;
#define mp make_pair
#define pb push_back
#define INF 1000000
#define PI 3.14159265358979323846
#define EPS 1e-9
int n;
double l, r;
bool test(double x, vd data){
    vector <pdd> ans;

    for(int i=0; i<data.size(); i++){
        if(x <= data[i].first.second - EPS){
            double height = data[i].first.second;
            double position = data[i].first.first;
            double angle = data[i].second*PI/180;
            ans.pb(mp(position-tan(angle)*(height-x),position+tan(angle)*(height-x)));
        }
    }
    sort(ans.begin(), ans.end());
    if(ans.empty()) return false;
    double left = ans[0].first;
    double right = ans[0].second;

    for(int i=1; i<ans.size(); i++){
        if(ans[i].first < right + EPS)
            right = max(right, ans[i].second);
        else{
            if(l > left - EPS and r < right + EPS) return true;
            left = ans[i].first;
            right = ans[i].second;
        }
    }

    return l > left - EPS && r < right + EPS;
}


int main(){
    cin >> n >> l >> r;
    vd lights(n);
    for(int i=0; i<n; i++)
        cin >> lights[i].first.first >> lights[i].first.second >> lights[i].second;
    
    sort(lights.begin(), lights.end());
    double lo = -1.0;
    double hi = 1200.0;
    for(int _= 0; _<100; _++){
        double me = (lo+hi)/2.0;
        if(test(me, lights)) lo = me;
        else hi = me;
    }
    printf("%.10lf\n",(lo+hi)/2.0);
    return 0;
}