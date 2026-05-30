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
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
/*
    1. 不重叠区间 + 求最值 -> 区间dp
    2. 区间必须包含特定点 -> 预处理合法区间
    3. L <= 1e9, n <= 1e5 -> 离散化，将稀疏的大坐标 压缩成 紧凑的小坐标
    4. 普通的区间 DP 找前一个不冲突区间需要 O(n) 遍历 -> 前缀最大值查询 : 树状数组优化
*/
struct node {
    int l, r;
    bool operator<(const node& tp) const {
        if(r != tp.r) return r < tp.r;
        return l < tp.l;
    }
};

void solve(){
    int L, n, m;
    cin >> L >> n >> m;
    vector<node> c(n+1);
    for(int i = 1; i <= n; i++){
        cin >> c[i].l >> c[i].r;
    }
    vii a(m+1);
    for(int i = 1; i <= m; i++){
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    
    // 筛选合法区间
    vector<node> gd(1);
    for(int i = 1; i <= n; i++){
        auto it = lower_bound(a.begin()+1, a.end(), c[i].l);
        if(it != a.end() && *it <= c[i].r){
            gd.push_back(c[i]);
        }
    }
    int n1 = gd.size() - 1;
    if(n1 == 0){
        cout << 0 << endl;
        return;
    }
    
    sort(gd.begin() + 1, gd.end());
    
    // 离散化
    vii val;
    val.pb(0); 
    for(int i = 1; i <= n1; i++){
        val.pb(gd[i].l - 1);
        val.pb(gd[i].r);
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    
    int mx = val.size();
    vii tree(mx + 1, 0);
    
    auto update = [&](int x, int val) -> void {
        for(; x <= mx; x += x & -x) {
            tree[x] = max(tree[x], val);
        }
    };
    auto query = [&](int x) -> int {
        int res = 0;
        for(; x > 0; x -= x & -x) {
            res = max(res, tree[x]);
        }
        return res;
    };
    
    vii dp(n1 + 1); // dp[i] 记录选定第 i 个区间的最大收益
    int ans = 0; 
    for(int i = 1; i <= n1; i++){
        int last = lower_bound(val.begin(), val.end(), gd[i].l - 1) - val.begin() + 1;
        int r = lower_bound(val.begin(), val.end(), gd[i].r) - val.begin() + 1;
        dp[i] = query(last) + (gd[i].r - gd[i].l + 1);
        ans = max(ans, dp[i]);
        update(r, dp[i]);
    }
    cout << ans << endl;
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