#include <bits/stdc++.h>
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using ll = long long;
using namespace std;

#define v1 2 * node
#define v2 2 * node + 1
#define me (l + r) / 2

#define N 100005

struct Node {
    ll ans, lazy;
    Node() {}
    Node(ll _ans, ll _lazy) {ans = _ans, lazy = _lazy;}
};

Node tree[4*N];

void build(int node, int l, int r) {
    if (l == r) {
        tree[node].ans = 0;
        tree[node].lazy = 0;
        return;
    }
    build(v1, l, me);
    build(v2, me + 1, r);
    // + is any operation
    tree[node].ans = (tree[v1].ans + tree[v2].ans);
    tree[node].lazy = 0;
}

void push(int node, int l, int r) {
    if (tree[node].lazy == 0)
        return;
    // update tree[node] from lazy info
    tree[node].ans += (r - l + 1) * tree[node].lazy;
    // if child node is not a leaf
    if (l != r) {
        // propagate to children
        tree[v1].lazy += tree[node].lazy;
        tree[v2].lazy += tree[node].lazy;
    }
    // clear lazy node
    tree[node].lazy = 0;
}

void update(int lu, int ru, int node, int l, int r, int v) {
    push(node, l, r);
    if (l > ru || r < lu)
        return;

    if (l >= lu && r <= ru) {
        // update lazy values
        tree[node].lazy += v;
        push(node, l, r);
        return;
    }
    update(lu, ru, v1, l, me, v);
    update(lu, ru, v2, me + 1, r, v);
    // update parent from childs
    tree[node].ans = (tree[v1].ans + tree[v2].ans);
}

ll query(int lq, int rq, int node, int l, int r) {
    push(node, l, r);
    if (l > rq || r < lq)
        return 0;
    if (l >= lq && r <= rq)
        return tree[node].ans;
    return (query(lq, rq, v1, l, me) + query(lq, rq, v2, me + 1, r));
}

int main(){
    FIFO;
    int t; cin >> t;
    while(t--){
        int n, c; cin >> n >> c;
        build(1, 0, n-1);
        for(int i=0; i<c; i++){
            int type; cin >> type;
            if(type == 0){
                int p, q, v; cin >> p >> q >> v;
                update(p-1, q-1, 1, 0, n-1, v);
            }
            else{
                int p, q; cin >> p >> q;
                cout << query(p-1, q-1, 1, 0, n-1) << '\n';
            }
        }
    }
    return 0;
}