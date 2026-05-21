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
    struct node {
        int mn;
        int lazy;
    };
    int n;
    vector<node> tree;
    vector<int> a; 

    SegTree(int _n){
        n = _n;
        tree.resize((n+1) << 2);
        a.resize(n+1, inf);
    }
    void push_up(int u) {
        tree[u].mn = min(tree[u << 1].mn, tree[u << 1 | 1].mn);
    }
    void push_down(int u){
        if(tree[u].lazy != 0){
            tree[u << 1].mn += tree[u].lazy;
            tree[u << 1].lazy += tree[u].lazy;
            tree[u << 1 | 1].mn += tree[u].lazy;
            tree[u << 1 | 1].lazy += tree[u].lazy; 
            tree[u].lazy = 0;
        }
    }
    void build(int u, int l, int r){
        tree[u].lazy = 0;
        if(l == r){
            tree[u].mn = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        push_up(u);
    }

    void add(int u, int l, int r, int pos, int val){
        if(l == r){
            tree[u].mn = val;
            return;
        }
        push_down(u);
        int mid = (l + r) >> 1;
        if(pos <= mid) add(u << 1, l, mid, pos, val);
        else add(u << 1 | 1, mid + 1, r, pos, val);
        push_up(u);
    }
    void modify(int u, int l, int r, int ql, int qr, int k) {
        if(l >= ql && qr >= r) {
            tree[u].mn += k; 
            tree[u].lazy += k;              
            return;
        }
        push_down(u); 
        int mid = (l + r) >> 1;
        if (ql <= mid) modify(u << 1, l, mid, ql, qr, k);
        if (qr > mid) modify(u << 1 | 1, mid + 1, r, ql, qr, k);
        push_up(u); 
    }

    int query(int u, int l, int r, int ql, int qr) {
        if(ql <= l && r <= qr) {
            return tree[u].mn;
        }
        push_down(u); 
        int mid = (l + r) >> 1;
        int res = inf; 
        if (ql <= mid) res = min(res, query(u << 1, l, mid, ql, qr));
        if (qr > mid) res = min(res, query(u << 1 | 1, mid + 1, r, ql, qr));
        return res;
    }
};
void solve(){
    int n, r; cin >> n >> r;
    vector<int> a(n+1), c(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> c[i];
    
    vector<int> pre(n+1);
    for(int i = 1; i <= n; i++){
        pre[i] = (pre[i-1] + a[i]) % r;
    }
    unordered_map<int, int> mp; 
    int cnt = 0;
    int L = 0;
    vector<int> dp(n+1);

    SegTree tr(n);
    tr.build(1,1,n);

    int pos = n + 1;
    for(int i = 1; i <= n; i++){
        if(pre[i] == 0){
            pos = i;
            break;
        }
    }
    for(int i = 1; i <= n; i++){
        if(mp[pre[i]] == 0) cnt++;
        mp[pre[i]]++;
        
        while(cnt == r){
            L++;
            mp[pre[L]]--;
            if(mp[pre[L]] == 0) cnt--;
        }
        tr.add(1, 1, n, i, dp[i-1] + c[i]);
        
        int mn = tr.query(1, 1, n, L + 1, i);
        
        if(i < pos) {
            dp[i] = min(0LL, mn); 
        }else{
            dp[i] = mn;
        }
    }
    cout << dp[n] << endl;
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