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
struct BIT {
    int n;
    vector<int> tr;
    BIT(int _n) : n(_n), tr(_n + 1, 0) {}
    int lowbit(int x) { return x & -x; }
    
    void add(int x, int c) {
        for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
    }
    
    int query(int x) {
        int res = 0;
        for (int i = x; i > 0; i -= lowbit(i)) res += tr[i];
        return res;
    }
    
    int query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

void solve(){
    int n,m; cin >> n >> m;
    // R[l] 存以 l 为起点的所有右端点
    vector<vector<int>> R(n+1), L(n+1);
    for(int i = 1; i <= m; i++){
        int l,r; cin >> l >> r;
        R[l].push_back(r);
        L[r].push_back(l);
    }
    for(int i = 1; i <= n; i++){
        if(L[i].size())sort(L[i].begin(), L[i].end());
        if(R[i].size())sort(R[i].begin(), R[i].end());
    }
    int q; cin >> q;
    // 离线查询处理：que[s] 存储所有起点为 s 的查询 (目标右端点 t, 查询编号 id)
    vector<vector<pii>> que(n+1);
    for(int i = 1; i <= q; i++){
        int s,t; cin >> s >> t;
        que[s].push_back({t, i});
    }
    vector<int> ans(q+1);
    BIT bit(n);
    for(int s = n; s >= 1; s--){
        for(int r: R[s]) bit.add(r, 1);
        for(auto& [t, id]: que[s]){
            int mxr = -1; // 找最远右边界
            auto it = upper_bound(R[s].begin(), R[s].end(), t);
            if(it != R[s].begin()){
                mxr = *(it - 1);
            }
            int mnl = inf; // 找最远左边界
            auto it1 = lower_bound(L[t].begin(), L[t].end(), s);
            if(it1 != L[t].end()){
                mnl = *it1;
            }

            if(mxr == -1 || mnl == inf){
                ans[id] = 0;
            }else if(mxr == t && mnl == s){
                // 查找[s, t]里面线段个数, 因为倒叙遍历, 只枚举到s, 故查找[1,t]即可
                int cnt = bit.query(t);
                ans[id] = (cnt >= 2);
            }else if(mxr >= mnl - 1){
                ans[id] = 1;
            }else{
                ans[id] = 0;
            }
        }
    }
    for(int i = 1; i <= q; i++){
        cout << (ans[i] == 0 ? "No" : "Yes") << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}