#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define N 50005
#define INF (1LL<<60)

ll a[N];

struct Node{
    ll tree = -INF;
    ll preff = -INF;
    ll suff = -INF;
    ll sum = -INF;
};

Node ST[4*N];

void set_node(Node &x, ll tree, ll preff, ll suff, ll sum){
    x.tree = tree;
    x.preff = preff;
    x.suff = suff;
    x.sum = sum;
}

void clean(){
    for(int i=0; i<4*N; i++)
        set_node(ST[i], -INF, -INF, -INF, -INF);
}

void build(int node, int l, int r){
    if(r - l < 1){
        set_node(ST[node], a[l], a[l], a[l], a[l]);
        return;
    }
    
    int m = (l+r)/2;

    build(node*2, l, m);
    build(node*2+1, m+1, r);

    ST[node].sum = ST[node*2].sum + ST[node*2 + 1].sum;
    ST[node].preff = max(ST[node*2].preff, ST[node*2].sum + ST[node*2 + 1].preff);
    ST[node].suff = max(ST[node*2 + 1].suff, ST[node*2 + 1].sum + ST[node*2].suff);
    ST[node].tree = max(ST[node*2].tree, max(ST[node*2 + 1].tree, ST[node*2 + 1].preff + ST[node*2].suff));
}

Node answer(int node, int start, int end, int l, int r){
    Node ans;

    if(start > end or start > r or end < l){
        set_node(ans, -INF, -INF, -INF, 0);
        return ans;
    }

    if(start >=l and end <= r){
        set_node(ans, ST[node].tree, ST[node].preff, ST[node].suff, ST[node].sum);
        return ans;
    }

    int m = (start+end)/2;

    Node p1 = answer(2*node, start, m, l, r);
    Node p2 = answer(2*node+1, m+1, end, l, r);

    ll a1 = max(p1.tree, max(p2.tree, p1.suff + p2.preff));
    ll a2 = max(p1.preff, p1.sum + p2.preff);
    ll a3 = max(p2.suff, p2.sum + p1.suff);
    ll a4 = p1.sum + p2.sum;

    set_node(ans, a1, a2, a3, a4);
    return ans;
}

int main(){
    FIFO;
    int n; cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    
    clean();
    
    build(1, 0, n-1);
    
    int m;
    cin >> m;
    
    while(m--){
        int x, y;
        cin >> x >> y;
        x--; y--;
        Node ans = answer(1, 0, n-1, x, y);
        cout << ans.tree << '\n';
    }
    return 0;
}