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
const int N = 2e5+5, mod = 1e9+7, inf = 1e18 + 5;

struct SegTree {
    struct Node {
        int mn;
        int lazy;
    };
    int n;
    vector<Node> tree;
    vector<int> a;

    SegTree(int _n) {
        n = _n;
        tree.resize((n + 1) * 4); 
        a.resize(n + 1, 0);
    }

    void push_up(int u) {
        tree[u].mn = min(tree[u << 1].mn , tree[u << 1 | 1].mn);
    }

    void push_down(int u, int l, int r) {
        if (tree[u].lazy != 0) { 
            int tag = tree[u].lazy;
            tree[u << 1].mn += tag;
            tree[u << 1].lazy += tag;

            tree[u << 1 | 1].mn += tag;
            tree[u << 1 | 1].lazy += tag; 

            tree[u].lazy = 0;
        }
    }

    void build(int u, int l, int r) {
        tree[u].lazy = 0; 
        if(l == r) {
            tree[u].mn = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        push_up(u);
    }
    
    void modify(int u, int l, int r, int ql, int qr, int k) {
        if(l >= ql && qr >= r) {
            tree[u].mn += k; 
            tree[u].lazy += k;              
            return;
        }
        push_down(u, l, r); 
        
        int mid = (l + r) >> 1;
        if (ql <= mid) modify(u << 1, l, mid, ql, qr, k);
        if (qr > mid) modify(u << 1 | 1, mid + 1, r, ql, qr, k);
        
        push_up(u); 
    }

    int query(int u, int l, int r, int ql, int qr) {
        if(ql <= l && r <= qr) {
            return tree[u].mn;
        }
        
        push_down(u, l, r); 
        int mid = (l + r) >> 1;
        int res = inf;
        if (ql <= mid) res = min(res, query(u << 1, l, mid, ql, qr));
        if (qr > mid) res = min(res, query(u << 1 | 1, mid + 1, r, ql, qr));
        
        return res;
    }
    
    int find(int u, int l, int r, int ql, int qr){
        if(l > qr || r < ql || tree[u].mn > 0) return -1;
        if (l == r) return l;
        push_down(u, l, r);
        int mid = (l + r) >> 1;
        int res = find(u << 1, l, mid, ql, qr);
        if (res != -1) return res;
        return find(u << 1 | 1, mid + 1, r, ql, qr);
    }
};

void solve(){
    int n, a; cin >> n >> a;
    vii v(n+1);
    int cnt = 0, sum = 0;
    SegTree seg(n);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        seg.a[i] = seg.a[i-1];
        if(v[i] <= a){
            cnt++;
            sum += v[i];
            seg.a[i]++;
        }
    }
    seg.build(1,1,n);
    
    int m; cin >> m;
    vector<array<int,2>> qs(m+1);
    for(int i = 1; i <= m; i++){
        int b; cin >> b;
        qs[i] = {b, i};
    }
    
    sort(qs.begin() + 1, qs.end(), [](auto x, auto y){
        return x[0] > y[0];
    });
    
    vector<pii> sell;
    for(int i = 1; i <= n; i++){
        if(v[i] > a) sell.push_back({v[i], i});
    }
    sort(sell.begin(), sell.end(), [](auto x, auto y){
        return x.fi > y.fi;
    });
    
    set<int> st; 
    int res = 0; 
    int p = 0;
    vii ans(m+1);
    
    for(int i = 1; i <= m; i++){
        auto [cb, id] = qs[i];
        while(p < sell.size() && sell[p].fi >= cb){
            auto [val_x, x] = sell[p]; 
            
            int kc = seg.query(1,1,n,x,n);
            if(kc > 0){
                st.insert(x);
                res += val_x;
                seg.modify(1,1,n,x,n,-1);
            } else {
                int z = seg.find(1,1,n,x,n);
                if(z != -1){
                    auto it = st.upper_bound(z);
                    if(it != st.begin()){
                        --it;
                        int y = *it;
                        if(y > x){
                            res -= v[y]; 
                            seg.modify(1,1,n,y,n,1);
                            st.erase(it);
                            st.insert(x);
                            res += val_x;
                            seg.modify(1,1,n,x,n,-1);
                        }
                    }
                }
            }
            p++;
        }
        ans[id] = res + (cnt - st.size()) * v[n] - sum;
    }
    rep(i,1,m) cout << ans[i] << " \n"[i==m];
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