#include <bits/stdc++.h>

using namespace std;
using ll = long long;
string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

ll solve(int r, int c, vector <vector <int> > & g){
    ll ans = 0;
    ll product = 1;
    if(c+4 < 20){
        for(int i=0; i<4; i++)  
            product *= g[r][c+i];
        ans = max(ans, product);
        product = 1;
    }
    if(c-4 >= 0){
        for(int i=0; i<4; i++)  
            product *= g[r][c-i];
        ans = max(ans, product);
        product = 1;
    }
    if(r+4 < 20){
        for(int i=0; i<4; i++)  
            product *= g[r+i][c];
        ans = max(ans, product);
        product = 1;
    }
    if(r-4 >= 0){
        for(int i=0; i<4; i++)  
            product *= g[r-i][c];
        ans = max(ans, product);
        product = 1;
    }
    if(r+4 < 20 && c+4 < 20){
        for(int i=0; i<4; i++)
            product *= g[r+i][c+i];
        ans = max(ans, product);
        product = 1;
    }
    if(r+4 < 20 && c-4 >= 0){
        for(int i=0; i<4; i++)
            product *= g[r+i][c-i];
        ans = max(ans, product);
        product = 1;
    }
    if(r-4 >= 0 && c+4 < 20){
        for(int i=0; i<4; i++)
            product *= g[r-i][c+i];
        ans = max(ans, product);
        product = 1;
    }
    if(r-4 >= 0 && c-4 >= 0){
        for(int i=0; i<4; i++)
            product *= g[r-i][c-i];
        ans = max(ans, product);
        product = 1;
    }
    return ans;
}

int main()
{

    vector<vector<int>> grid(20);

    for (int i = 0; i < 20; i++) {
        grid[i].resize(20);

        string grid_row_temp_temp;
        getline(cin, grid_row_temp_temp);

        vector<string> grid_row_temp = split(rtrim(grid_row_temp_temp));

        for (int j = 0; j < 20; j++) {
            int grid_row_item = stoi(grid_row_temp[j]);

            grid[i][j] = grid_row_item;
        }
    }
    ll ans = 0;
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            ans = max(ans, solve(i, j, grid));
        }
    }
    cout << ans << '\n';
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
