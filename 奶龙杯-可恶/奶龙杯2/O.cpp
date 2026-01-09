#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
int lowbit(int x){ return (x & -x);}
double pi = acos(-1);
const int N = 5e6+10, mod = 998244353, inf = 1e18 + 5;
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
int n,k; 
int fact[N], infact[N];
void init(){
    fact[0] = 1;
    for(int i = 1; i < N; i++) fact[i] = fact[i-1] * i % mod;
    infact[N-1] = fpow(fact[N-1], mod - 2);
    for(int i = N-2; i >= 0; i--) infact[i] = infact[i+1] * (i + 1) % mod;
}
int A(int n, int m){
    if(m < 0 || m > n) return 0;
    return fact[n] * infact[n-m] % mod;
}

// 树状数组维护可用数数量
int tr[N];
void add(int x, int w){
    for(int i = x; i <= n; i += lowbit(i)){
        tr[i] += w;
    }
}
int query(int x){
    int res = 0;
    for(int i = x; i; i -= lowbit(i)){
        res += tr[i];
    }
    return res;
}

// 线段树维护不包含 t 且 b 严格小于 P 的方案数
struct node{
    int sum;
    int lz_add;
    int lz_mul;
}tree[N << 2];
void push_up(int i){
    tree[i].sum = (tree[i << 1].sum + tree[i << 1 | 1].sum) % mod;
}
void push_down(int i,int l, int r){
    int mid = (l + r) >> 1;
    if(tree[i].lz_mul != 1){
        tree[i << 1].lz_mul = tree[i << 1].lz_mul * tree[i].lz_mul % mod;
        tree[i << 1].lz_add = tree[i << 1].lz_add * tree[i].lz_mul % mod;
        tree[i << 1].sum = tree[i << 1].sum * tree[i].lz_mul % mod;
        tree[i << 1 | 1].lz_mul = tree[i << 1 | 1].lz_mul * tree[i].lz_mul % mod;
        tree[i << 1 | 1].lz_add = tree[i << 1 | 1].lz_add * tree[i].lz_mul % mod;
        tree[i << 1 | 1].sum = tree[i << 1 | 1].sum * tree[i].lz_mul % mod;
        tree[i].lz_mul = 1;
    }
    if(tree[i].lz_add){
        tree[i << 1].lz_add = (tree[i << 1].lz_add + tree[i].lz_add) % mod;
        tree[i << 1].sum = (tree[i << 1].sum + 1ll * tree[i].lz_add * (mid - l + 1)) % mod;
        tree[i << 1 | 1].lz_add = (tree[i << 1| 1].lz_add + tree[i].lz_add) % mod;
        tree[i << 1 | 1].sum = (tree[i << 1| 1].sum + 1ll * tree[i].lz_add * (r - mid)) % mod;
        tree[i].lz_add = 0;
    }
}
void build(int u, int l, int r){
    tree[u].lz_add = 0; 
    tree[u].lz_mul = 1; 
    tree[u].sum = 0;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid+1, r);
}
void change_mul(int i, int l, int r, int pl, int pr, int v){
    if(l >= pl && r <= pr){
        tree[i].sum = tree[i].sum * v % mod;
        tree[i].lz_add = tree[i].lz_add * v % mod;
        tree[i].lz_mul = tree[i].lz_mul * v % mod;
        return;
    }
    push_down(i,l,r);
    int mid = (l + r) >> 1;
    if(pl <= mid) change_mul(i << 1, l, mid, pl, pr, v);
    if(pr >  mid) change_mul(i << 1 | 1, mid+1, r, pl, pr, v);
    push_up(i);
}
void change_add(int i, int l, int r, int pl, int pr, int v){
    if(pl > pr) return; // 不加RE!!!
    if(l >= pl && r <= pr){
        tree[i].sum = (tree[i].sum + v * (r-l+1) % mod) % mod;
        tree[i].lz_add = (tree[i].lz_add + v) % mod;
        return;
    }
    push_down(i,l,r);
    int mid = (l + r) >> 1;
    if(pl <= mid) change_add(i << 1, l, mid, pl, pr, v);
    if(pr >  mid) change_add(i << 1 | 1, mid+1, r, pl, pr, v);
    push_up(i);
}
int query(int i, int l, int r, int id) {
    if(l == r) return tree[i].sum % mod;
    push_down(i, l, r);
    int mid = (l + r) >> 1;
    if(id <= mid) return query(i << 1, l, mid, id);
    else return query(i << 1 | 1, mid+1, r, id);
}
int ans[N],vis[N],p[N];
void solve(){
    init();
    cin >> n >> k;
    // vector<int> ans(N),vis(N),p(N);
    for(int i = 1; i <= k; i++) cin >> p[i];
    for(int i = 1; i <= n; i++) add(i,1);
    // sum : b <= p 的方案数
    int sum = 1; 
    for(int i = 1; i <= k; i++){
        int cnt = query(p[i]-1);
        sum = (sum + cnt * A(n-i,k-i) % mod) % mod;
        add(p[i],-1);
    }
    for(int i = 0; i <= n; i++) tr[i] = 0;
    for(int i = 1; i <= n; i++) add(i,1);
    // t在p中
    build(1,1,n);
    for(int i = 1; i <= k; i++){
        int u = p[i];
        int cnt = query(u-1);
        change_mul(1,1,n,1,n,n-i);
        change_add(1,1,n,1,u-1,cnt-1);
        change_add(1,1,n,u,n,cnt);
        int cur = query(1,1,n,u) * A(n-i-1,k-i) % mod;
        ans[u] = (sum - cur + mod) % mod;
        vis[u] = 1;
        add(u,-1);
    }
    // t不在p中
    for(int t = 1; t <= n; t++){
        if(vis[t] == 0){
            int temp = (query(1,1,n,t) + 1) % mod;
            ans[t] = (sum - temp + mod) % mod;
        }
        cout << ans[t] << endl;
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