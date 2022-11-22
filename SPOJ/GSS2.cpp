#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define v1 2*node
#define v2 2*node+1
#define me (l+r)/2

#define N 100005
vector <int> arr;

struct Query{
    int l = 0;
    int r = 0;
    int id = 0;
};

struct Node {
    ll ans, lazy, best_lazy, sum;
    Node() {
        ans = 0;
        lazy = 0;
        best_lazy = 0;
        sum = 0;
    }
    Node(ll _ans, ll _lazy, ll _best_lazy, ll _sum) {
        ans = _ans;
        lazy = _lazy;
        best_lazy = _best_lazy;
        sum = _sum;
    }
};

Node tree[4*N];

void push(int node, int l, int r) {
    tree[v1].best_lazy = max(tree[v1].best_lazy, tree[v1].lazy + tree[node].best_lazy);
    tree[v2].best_lazy = max(tree[v2].best_lazy, tree[v2].lazy + tree[node].best_lazy);
    tree[v1].lazy += tree[node].lazy;
    tree[v2].lazy += tree[node].lazy;
    tree[v1].ans = max(tree[v1].ans, tree[v1].sum + tree[node].best_lazy);
    tree[v2].ans = max(tree[v2].ans, tree[v2].sum + tree[node].best_lazy);
    tree[v1].sum += tree[node].lazy;
    tree[v2].sum += tree[node].lazy;
    
    tree[node].lazy = tree[node].best_lazy = 0;
}

void merge(Node &cur, Node left, Node right){
    cur.ans = max(left.ans, right.ans);
    cur.sum = max(left.sum, right.sum);
}

void update(int lu, int ru, int node, int l, int r, int v) {
    if(l > ru || r < lu) return;
    
    if(l >= lu && r <= ru) {
        // update lazy values
        tree[node].best_lazy = max(tree[node].best_lazy, tree[node].lazy + v);
        tree[node].lazy += v;
        tree[node].ans = max(tree[node].ans, tree[node].sum + v);
        tree[node].sum += v;
        return;
    }
    push(node, v1, v2);
    update(lu, ru, v1, l, me, v);
    update(lu, ru, v2, me+1, r, v);
    // update parent from children
    merge(tree[node], tree[v1], tree[v2]);
}

Node query(int lq, int rq, int node, int l, int r) {
    if(l > rq || r < lq) return Node();
    if(l >= lq && r <= rq) return tree[node];
    push(node, v1, v2);
    Node ans;
    merge(ans, query(lq, rq, v1, l, me), query(lq, rq, v2, me + 1, r));
    return ans;
}

int main(){
    FIFO;
    int n; cin >> n;
    arr.resize(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int q; cin >> q;
    vector <Query> queries(q);
    for(int i=0; i<q; i++){
        Query qq;
        int x, y; cin >> x >> y;
        qq.l = x-1; qq.r = y-1; qq.id = i;
        queries[i] = qq;
    }
    sort(queries.begin(), queries.end(), [](Query a, Query b) {return a.r < b.r;});
    int query_indx = 0;
    ll ans[q];
    map <int, int> m;
    for(int i=0; i<n && query_indx < q; i++){
        int last_pos = 0;
        if(m.find(arr[i]) != m.end()) last_pos = m[arr[i]] + 1;
        update(last_pos, i, 1, 0, n-1, arr[i]);
        m[arr[i]] = i;
        while(query_indx < q && queries[query_indx].r == i){
            ans[queries[query_indx].id] = query(queries[query_indx].l, queries[query_indx].r, 1, 0, n-1).ans;
            query_indx++;
        }
    }
    for(int i=0; i<q; i++) cout << ans[i] << '\n';
    return 0;
}