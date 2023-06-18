#include <bits/stdc++.h>
using namespace std;
using dd = long double;
using _point = pair <dd, dd>;
using _circle = pair <dd, _point>; 
#define EPS 1e-8

double check_tangency(_circle c0, _circle c1){
    dd x0 = c0.second.first;
    dd y0 = c0.second.second;
    dd x1 = c1.second.first;
    dd y1 = c1.second.second;
    dd D = sqrt((x1-x0)*(x1-x0) + (y1-y0)*(y1-y0));
    return abs(abs(c0.first + c1.first) - D);
}

dd gen_radius(dd r0, dd r1, dd r2){
    dd k = 1/r0 + 1/r1 + 1/r2 + 2*sqrt(1/(r0*r1) + 1/(r1*r2) + 1/(r0*r2));
    return 1/k;
}

_point gen_coordinates(_circle c0, _circle c1, _circle c2, dd r){
    dd k0 = 1/c0.first;
    dd k1 = 1/c1.first;
    dd k2 = 1/c2.first;
    dd x0 = c0.second.first; dd y0 = c0.second.second;
    dd x1 = c1.second.first; dd y1 = c1.second.second;
    dd x2 = c2.second.first; dd y2 = c2.second.second;
    
    // (x0+iy0)*(x1+iy1) = x0x1 - y0y1 + i(x1y0 + x0y1)
    dd Sx = k0*k1*(x0*x1-y0*y1) + k1*k2*(x1*x2-y1*y2) + k0*k2*(x0*x2-y0*y2);
    dd Sy = k0*k1*(y0*x1+y1*x0) + k1*k2*(y1*x2+y2*x1) + k0*k2*(y0*x2+y2*x0);
    // cout << Sx/(k1*k2) << '\n';
    dd Cx = sqrt((sqrt(Sx*Sx+Sy*Sy)+Sx)/2);
    dd Cy = 0;
    if(Sy != 0) Cy = abs(Sy)/Sy*sqrt((sqrt(Sx*Sx+Sy*Sy)-Sx)/2);
    else
    	if(Sx < 0) Cy = sqrt(-Sx);
    dd x_1 = (k0*x0 + k1*x1 + k2*x2 + 2*Cx)*r;
    dd y_1 = (k0*y0 + k1*y1 + k2*y2 + 2*Cy)*r;
    dd x_2 = (k0*x0 + k1*x1 + k2*x2 - 2*Cx)*r;
    dd y_2 = (k0*y0 + k1*y1 + k2*y2 - 2*Cy)*r;
    _circle c_1 = make_pair(r, make_pair(x_1, y_1));
    _circle c_2 = make_pair(r, make_pair(x_2, y_2));
    dd error1 = (check_tangency(c_1, c0) + check_tangency(c_1, c1) + check_tangency(c_1, c2));
    dd error2 = (check_tangency(c_2, c0) + check_tangency(c_2, c1) + check_tangency(c_2, c2));
    
    if(error1 < error2) return make_pair(x_1, y_1);
    else return make_pair(x_2, y_2);

}

_circle gen_circle(vector <_circle> &v){
    dd r = gen_radius(v[0].first, v[1].first, v[2].first);
    _point p = gen_coordinates(v[0], v[1], v[2], r);
    _circle circle = make_pair(r, p);
    return circle;
}

void bfs(vector <vector <_circle> > &circles){
    vector <vector <int> > permutations = {{0, 1, 3}, {0, 2, 3}, {1, 2, 3}};
    for(int level=2; level<=6; level++){
        // cout << "#############################\n";
        // cout << "LEVEL " << level << '\n';
        vector <vector <_circle> > new_circles;
        for(auto circles_list: circles){
            _circle new_circle = gen_circle(circles_list);
            cout << "Circle[{" << new_circle.second.first << ", " << new_circle.second.second << "}, " << new_circle.first << "],\n";
            new_circles.push_back({circles_list[0], circles_list[1], new_circle});
            new_circles.push_back({circles_list[0], circles_list[2], new_circle});
            new_circles.push_back({circles_list[1], circles_list[2], new_circle});
        }
        // [0, 1, 2, 3]
        // [0, 1, 2], [0, 1, 3], [0, 2, 3], [1, 2, 3]
        circles = new_circles;
    }
}

double solve(vector <vector <dd> > &radius){
    dd s = 0;
    for(int i=0; i<3; i++) s += radius[3][i]*radius[3][i];
    for(int level=1; level<=10; level++){
        vector <vector <dd> > new_radius;
        for(auto r_list: radius){
            dd new_r = gen_radius(r_list[0], r_list[1], r_list[2]);
            new_radius.push_back({r_list[0], r_list[1], new_r});
            new_radius.push_back({r_list[0], r_list[2], new_r});
            new_radius.push_back({r_list[1], r_list[2], new_r});
            s += new_r*new_r;
        }
        radius = new_radius;
    }
    return s;
}

int main(){
    cout << setprecision(8);
    dd r_0 = 100000000;
    dd r_1 = r_0*sqrt((dd)(3))/(2+sqrt((dd)(3)));
    _circle c0 = make_pair(-r_0, make_pair(0, 0));
    _circle c1 = make_pair(r_1, make_pair(0, r_0-r_1));
    _circle c2 = make_pair(r_1, make_pair(sqrt(3)*(r_0-r_1)/2, -(r_0-r_1)/2));
    _circle c3 = make_pair(r_1, make_pair(-sqrt(3)*(r_0-r_1)/2, -(r_0-r_1)/2));
    // vector <vector <_circle> > circles = {{c0, c1, c2}, {c0, c1, c3}, {c0, c2, c3}, {c1, c2, c3}};
    // cout << "LEVEL 1\n";
    // for(int i=0; i<3; i++)
    //     cout << "Circle[{" << circles[3][i].second.first << ", " << circles[3][i].second.second << "}, " << circles[3][i].first << "],\n";
    // bfs(circles);
    vector <vector <dd> > radius = {{-r_0, r_1, r_1}, {-r_0, r_1, r_1}, {-r_0, r_1, r_1}, {r_1, r_1, r_1}};
    dd ans = solve(radius)/r_0; ans /= r_0;
    cout << 1-ans <<'\n';
    return 0;
}
