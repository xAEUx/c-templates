#include <bits/stdc++.h>
#define int long long int
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff first
#define ss second
#define pb push_back
#define rev reverse
#define all(x) x.begin(),x.end()
#define acc accumulate
#define sz size()
#define N 200005
using namespace std;
int arr[N];
struct node{
    int l, r, v = 0, lazy = 0;
    node *L = NULL, *R = NULL;
};
vector<node>ptr;
auto yeni(node *cur){
    auto i = new node;
    i->l = cur->l, i->r = cur->r;
    i->v = cur->v, i->lazy = cur->lazy;
    i->L = cur->L, i->R = cur->R;
    return i;
}
void push(node *cur){
    if(cur->lazy){
        cur->v += cur->lazy * (cur->r - cur->l + 1);
        if(cur->l != cur->r){
            cur->L = yeni(cur->L);
            cur->R = yeni(cur->R);
            cur->L->lazy += cur->lazy;
            cur->R->lazy += cur->lazy;
        }
        cur->lazy = 0;
    }
}
void build(node *cur){
    if(cur->L == NULL && cur->l != cur->r){
        cur->L = new node;
        cur->R = new node;
        int m = (cur->l + cur->r) / 2;
        cur->L->l = cur->l;
        cur->L->r = m;
        cur->R->l = m + 1;
        cur->R->r = cur->r;
    }
    if(cur->l == cur->r){
        cur->v = arr[cur->l - 1];
        return;
    }
    build(cur->L);
    build(cur->R);
    cur->v = cur->L->v + cur->R->v;
}
void update(node *cur, int ql, int qr, int val){
    push(cur);
    if(cur->l > qr || cur->r < ql) return;
    if(cur->l >= ql && cur->r <= qr){
        cur->lazy += val;
        push(cur);
        return;
    }
    cur->L = yeni(cur->L);
    cur->R = yeni(cur->R);
    update(cur->L, ql, qr, val);
    update(cur->R, ql, qr, val);
    cur->v = cur->L->v + cur->R->v;
}
int find(node *cur, int ql, int qr){
    push(cur);
    if(cur->l > qr || cur->r < ql) return 0;
    if(cur->l >= ql && cur->r <= qr) return cur->v;
    cur->L = yeni(cur->L);
    cur->R = yeni(cur->R);
    return find(cur->L, ql, qr) + find(cur->R, ql, qr);
}
void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    node root;
    root.l  = 1, root.r = n;
    build(&root);
    ptr.pb(root);
    while(q--){
        int l, r, val;
        cin >> l >> r >> val;
        node *newroot = yeni(&(ptr.back()));
        update(newroot, l, r, val);
        ptr.pb(*newroot);
    }
    cout << find(&ptr[4], 1, 4) << " ";
}
int32_t main(){
    fast_io
    int t;
    t = 1;
    while(t--)
        solve();
}       
