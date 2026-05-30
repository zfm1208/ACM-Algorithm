#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define vii vector<int>
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 998244353, inf = 1e18 + 5;\
int ksm(int a, int b) {
    int res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

vector<int> a;
struct SegTree {
    struct node {
        int l;
        int r;
        int sum; // 区间和
        int sum2; // 区间平方和
        int lz;
    };
    vector<node> tr;
    int n;
    SegTree(int _n){
        n = _n;
        tr.resize((n+1) << 2);
    }
    void push_donw(int p){
        if(tr[p].lz){
            int ulz = tr[p].lz % mod;
            int lenl = tr[p << 1].r  - tr[p].l + 1;
            int lenr = tr[p << 1 | 1].r  - tr[p << 1 | 1].l + 1;
            tr[p << 1].lz = (tr[p << 1].lz + ulz) % mod;
            tr[p << 1].sum2 = ((tr[p << 1].sum2 + lenl * ulz % mod * ulz % mod) % mod + 2 * ulz % mod * tr[p << 1].sum % mod) % mod;
            tr[p << 1].sum = (tr[p << 1].sum + lenl * ulz % mod) % mod;
            tr[p << 1 | 1].lz = (tr[p << 1 | 1].lz + ulz) % mod;
            tr[p << 1 | 1].sum2 = ((tr[p << 1 | 1].sum2 + lenr * ulz % mod * ulz % mod) % mod + 2 * ulz % mod * tr[p << 1 | 1].sum % mod) % mod;
            tr[p << 1 | 1].sum = (tr[p << 1 | 1].sum + lenr * ulz % mod) % mod;
            tr[p].lz = 0;
        }
    }
    void build(int p, int l, int r){
        tr[p] = {l, r, 0, 0, 0};
        if(l == r){
            tr[p].sum = a[l];
            tr[p].sum2 = a[l] * a[l] % mod;
            return;
        }
        int mid = l + r >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        tr[p].sum = (tr[p << 1].sum + tr[p << 1 | 1].sum) % mod;
        tr[p].sum2 = (tr[p << 1].sum2 + tr[p << 1 | 1].sum2) % mod;
    }
    
    void update(int p, int l, int r, int v){
        if(l <= tr[p].l && tr[p].r <= r){
            tr[p].lz += v;
            tr[p].sum2 = (tr[p].sum2 + 2 * v % mod * tr[p].sum % mod + (tr[p].r - tr[p].l + 1) * v % mod * v % mod) % mod;
            tr[p].sum = (tr[p].sum + (tr[p].r - tr[p].l + 1) * v % mod) % mod;
            return;
        }
        push_donw(p);
        int mid  = tr[p].l + tr[p].r >> 1;
        if(l <= mid) update(p << 1, l, r, v);
        if(r > mid) update(p << 1 | 1, l, r, v);
        tr[p].sum = (tr[p << 1].sum + tr[p << 1 | 1].sum) % mod;
        tr[p].sum2 = (tr[p << 1].sum2 + tr[p << 1 | 1].sum2) % mod;       
    }

    pii query(int p, int l, int r) {
        if(l <= tr[p].l && tr[p].r <= r){
            return {tr[p].sum, tr[p].sum2};
        }
        int mid = tr[p].l + tr[p].r >> 1;
        push_donw(p);
        if(r <= mid) return query(p << 1, l, r);
        if(l > mid) return query(p << 1 | 1, l, r);
        pii le = query(p << 1, l, r);
        pii ri = query(p << 1 | 1, l, r);
        pii res;
        res.fi = (le.first + ri.first) % mod;
        res.se = (le.second + ri.second) % mod;
        return res;
    }
};
void solve(){
    int n,q; cin >> n >> q;
    a.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    SegTree seg (n);
    seg.build(1, 1, n);
    for(int i = 1; i <= q; i++) {
        int op, l, r, v;
        cin >> op;
        if(op == 1){
            cin >> l >> r >> v;
            seg.update(1, l, r, v);
        }else{
            cin >> l >> r;
            pii ans = seg.query(1, l, r);
            cout << (ans.first * ans.first % mod - ans.second + mod) % mod * ksm(2, mod - 2) % mod << endl;;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}