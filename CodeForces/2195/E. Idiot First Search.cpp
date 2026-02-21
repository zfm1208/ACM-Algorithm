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
struct node {
    int l,r;
};
void solve(){
    int n; cin >> n;
    vector<node> tree(n+1);
    for(int i = 1; i <= n; i++){
        int l,r; cin >> l >> r;
        tree[i] = {l,r};
    }
    vector<int> e(n+1); // 逃离以 u 为根的子树所需的时间
    auto dfs = [&](auto& self, int u) -> void {
        if(tree[u].l == 0){
            e[u] = 1; // 叶子节点，直接向上走 + 1
            return;
        }
        self(self, tree[u].l);
        self(self, tree[u].r);
        e[u] = (e[tree[u].l] + e[tree[u].r] + 3) % mod; // 向左向右向上 + 3
    };
    dfs(dfs,1);// 自底向上，计算每个节点作为一个“独立关卡”的通关时间

    vector<int> ans(n+1);
    auto dfs1 = [&](auto&self, int u, int sum) -> void {
        // 当前节点的答案 = (父辈们的总时间) + (当前节点的通关时间)
        ans[u] = (e[u] + sum) % mod; 
        if(tree[u].l != 0){
            self(self, tree[u].l, ans[u]);
            self(self, tree[u].r, ans[u]);
        }
    };
    dfs1(dfs1, 1, 0);// 自顶向下，计算“前缀和”，把通关路上所有关卡的时间加起来
    for(int i = 1; i <= n; i++) cout << ans[i] << " \n"[i==n];
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