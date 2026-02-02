#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, inf = 1e18 + 5;
int mod;
int phi;
int get_phi(int n){
    int ans = n;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            ans = ans / i * (i-1);
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1) ans = ans / n * (n-1);
    return ans;
}
int ksm(int a, int b){
    // a^b % p  == a ^ (b % phi + phi) % p   (b >= phi)
    if(b >= phi){
        b = b % phi + phi;
    }
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
struct SegTree {
    struct node{
        int cnt[35];
        int tag[35];
        void init(){
            for(int i = 0;i < 35; i++){
                cnt[i] = 0;
                tag[i] = i;
            }
        }
    };

    vector<node> tree;
    vector<int> a;
    SegTree(int n) {
        tree.resize((n+1) << 2);
        a.resize(n+1);
    }
    
    void push_up(int u) {
        for(int i = 0; i < mod; i++){
            tree[u].cnt[i] = tree[u << 1].cnt[i] + tree[u << 1 | 1].cnt[i];
        }
    }

    void build(int i, int l, int r) {
        tree[i].init();
        if(l == r){
            tree[i].cnt[a[l] % mod]++;
            return;
        }
        int mid = (l + r) >> 1;
        build(i << 1, l, mid);
        build(i << 1 | 1, mid + 1, r);
        push_up(i);
    }

    void apply_tag(int u, const int tag[]) {
        int new_cnt[35] = {0};
        int new_tag[35];
        for(int i = 0; i < mod; i++){
            new_cnt[tag[i]] += tree[u].cnt[i];
            new_tag[i] = tag[tree[u].tag[i]];
        }
        for(int i = 0; i < mod; i++){
            tree[u].cnt[i] = new_cnt[i];
            tree[u].tag[i] = new_tag[i];
        }
    }
    void push_down(int u) {
        bool ok = 0;
        for(int i = 0; i < mod; i++){
            if(tree[u].tag[i] != i){
                ok = 1;
                break;
            }
        }
        if(ok){
            apply_tag(u << 1, tree[u].tag);
            apply_tag(u << 1 | 1, tree[u].tag);
            for(int i = 0; i < mod; i++){
                tree[u].tag[i] = i;
            }
        }
    }
    void modify(int u, int l, int r, int ql, int qr, const int ys[]) {
        if(ql <= l && r <= qr) {
            apply_tag(u, ys);
            return;
        }
        push_down(u);
        int mid = (l + r) >> 1;
        if(ql <= mid) modify(u << 1, l, mid, ql, qr, ys);
        if(qr > mid) modify(u << 1 | 1, mid + 1, r, ql, qr, ys);
        push_up(u);
    }
    int query(int u, int l, int r, int ql, int qr, int k) {
        if(ql <= l && r <= qr) {
            int res = 0;
            for(int v = 0; v < mod; v++) {
                if(tree[u].cnt[v] == 0) continue;
                int val = ksm(v, k); 
                res = (res + tree[u].cnt[v] * val) % mod;
            }
            return res;
        }
        push_down(u);
        int mid = (l + r) >> 1;
        int res = 0;
        if(ql <= mid) res = (res + query(u << 1, l, mid, ql, qr, k)) % mod;
        if(qr > mid) res = (res + query(u << 1 | 1, mid + 1, r, ql, qr, k)) % mod;
        return res;
    }

    int ask(int u, int l, int r, int ql, int qr) {
        if(ql <= l && r <= qr) {
            if(tree[u].cnt[0] > 0) return 0;
            int res = 1;
            for(int v = 1; v < mod; v++) {
                if(tree[u].cnt[v] == 0) continue;
                res = res * ksm(v, tree[u].cnt[v]) % mod;
            }
            return res;
        }
        push_down(u);
        int mid = (l + r) >> 1;
        int res = 1;
        if(ql <= mid) res = res * ask(u << 1, l, mid, ql, qr) % mod;
        if(qr > mid) res = res * ask(u << 1 | 1, mid + 1, r, ql, qr) % mod;
        return res;
    }
};
void solve(){
    int n; cin >> n >> mod;
    phi = get_phi(mod);
    SegTree st(n);
    for(int i = 1; i <= n; i++) cin >> st.a[i];
    st.build(1, 1, n);
    int q; cin >> q;
    while(q--){
        int op,l,r,k; cin >> op >> l >> r >> k;
        int ys[35]; 
        if(op == 1){
            for(int i = 0; i < mod; i++) ys[i] = (i + k) % mod;
            st.modify(1, 1, n, l, r, ys);
        }else if(op == 2){
            for(int i = 0; i < mod; i++) ys[i] = (i * k) % mod;
            st.modify(1, 1, n, l, r, ys);
        }else if(op == 3){
            for(int i = 0; i < mod; i++) ys[i] = ksm(i, k);
            st.modify(1, 1, n, l, r, ys);
        }else if(op == 4){
            cout << st.query(1, 1, n, l, r, k) << endl;
        }else{
            cout << st.ask(1, 1, n, l, r) << endl;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}