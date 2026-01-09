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
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
/*
    不难发现，正着去找每一步该选哪些点，不好实现，我们逆向思维，看看什么限制了我们选点
    <1> 同一层的每次只能选一个
        若这一层有k个点，则至少需要k次
    <2> 父亲和孩子每次只能选一个 
        若一个节点有k个孩子，那么孩子选完需要k次，该节点选完需要1次，共(k+1)次
    不难发现ans就是这两个条件最优解的最大值
*/
void solve(){
    int n; cin >> n;
    vector<vector<int>> e(n+1);
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    int ans = 0;
    vector<int> dep(n+1),child(n+1);
    int mx_dep = 0;
    auto dfs = [&] (auto& self, int u, int fa, int d) -> void {
        dep[d]++;
        mx_dep = max(mx_dep,d);
        int cnt = 0;
        for(auto v: e[u]){
            if(v == fa) continue;
            cnt++;
            self(self,v,u,d+1);
        }
        child[u] = cnt;
    };
    dfs(dfs,1,0,1);
    for(int i = 1; i <= mx_dep; i++){
        ans = max(ans,dep[i]);
    }
    for(int i = 1; i <= n; i++){
        ans = max(ans,child[i] + 1);
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
/*
10
6 8
9 7
4 10
5 9
4 2
3 8
6 5
1 5
1 10

ans = 3

p1 5 4 7 3
p2 1 8 9
p3 6 2
*/
