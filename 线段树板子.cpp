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
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;

struct SegTree {
    struct Node {
        int l, r;      
        int sum;        
        int mx, mn;     
        int lz;        
    };
    vector<Node> tr;    
    SegTree(int n) {
        tr.resize(n * 4 + 10);
    }
    void pushup(int u){
        tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
        tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
        tr[u].mn = min(tr[u << 1].mn, tr[u << 1 | 1].mn);
    }
    void pushdown(int u){
        if(tr[u].lz){ 
            int lz = tr[u].lz;
            int left = u << 1, right = u << 1 | 1;

            tr[left].lz += lz;
            tr[left].sum += lz * (tr[left].r - tr[left].l + 1);
            tr[left].mx += lz;
            tr[left].mn += lz;

            tr[right].lz += lz;
            tr[right].sum += lz * (tr[right].r - tr[right].l + 1);
            tr[right].mx += lz;
            tr[right].mn += lz;

            tr[u].lz = 0;
        }
    }

    void build(int u, int l, int r, const vector<int>& a) {
        tr[u] = {l, r, 0, -inf, inf, 0}; 
        if(l == r){
            tr[u].sum = a[l];
            tr[u].mx = a[l];
            tr[u].mn = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid, a);
        build(u << 1 | 1, mid + 1, r, a);
        pushup(u);
    }

    // 区间修改
    void update(int i, int l, int r, int v) {
        if(l <= tr[i].l && tr[i].r <= r){
            tr[i].sum += v * (tr[i].r - tr[i].l + 1);
            tr[i].mx += v;
            tr[i].mn += v;
            tr[i].lz += v;
            return;
        }
        pushdown(i);
        int mid = (tr[i].l + tr[i].r) >> 1;
        if (l <= mid) update(i << 1, l, r, v);
        if (r > mid)  update(i << 1 | 1, l, r, v);
        pushup(i);
    }

    // 区间查询
    Node query(int i, int l, int r) {
        if(l <= tr[i].l && tr[i].r <= r){
            return tr[i];
        }
        pushdown(i); 
        int mid = (tr[i].l + tr[i].r) >> 1;
        if (r <= mid) return query(i << 1, l, r);
        if (l > mid)  return query(i << 1 | 1, l, r);
        Node leftRes = query(i << 1, l, r);
        Node rightRes = query(i << 1 | 1, l, r);
        Node res;
        res.l = tr[i].l; res.r = tr[i].r;
        res.sum = leftRes.sum + rightRes.sum;
        res.mx = max(leftRes.mx, rightRes.mx);
        res.mn = min(leftRes.mn, rightRes.mn);
        return res;
    }
};
void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    SegTree st(n);
    st.build(1, 1, n, a);
    while(q--){
        int op; cin >> op;
        if(op == 1){ 
            // 区间修改: [l, r] 都加上 k
            int l, r, k;
            cin >> l >> r >> k;
            st.update(1, l, r, k);
        } else {
            // 区间查询 
            int l, r; cin >> l >> r;
            auto res = st.query(1, l, r);
            cout << res.sum << endl;
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