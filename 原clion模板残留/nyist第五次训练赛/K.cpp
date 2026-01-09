//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define per(i,l,r) for(int i = l; i >= r; i--)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
double pi = acos(-1);
const int mod1 = 1e9 + 7,mod2 = 998244353,inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
int n,u,v;
vector<int> a(N);
vector<int> b[N]; // 邻接表存边
vector<int> fa;
vector<bool> vis;
int ok = 1;
void dfs(int x){
    if(vis[x] || fa[x] == -1) return;
    vis[x] = true;
    for(auto i : b[x]){
        if(i == fa[x]) continue;
        if(fa[i] != -1 && fa[i] != x){ok=0;return;}
        fa[i] = x;
        dfs(i);
    }
}
void solve() {
    cin >> n;ok=1;
    fa.clear();fa.resize(n + 1);
    vis.clear();vis.resize(n + 1);
    rep(i,1,n) b[i].clear(),fa[i] = -1;
    rep(i,1,n) cin >> a[i];
    for(int i = 1; i < n; i++){
        cin >> u >> v;
        b[u].pb(v);b[v].pb(u);
        // 强制父亲节点
        if(a[u] * 2 < a[v]){
            if(fa[v] != -1) ok=0;
            fa[v] = u;
        }
        else if(a[v] * 2 < a[u]){
            if(fa[u] != -1) ok=0;
            fa[u] = v;
        }
        else {

        }
    }
    for(int i = 1; i <= n; i++)dfs(i);
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]) cnt++;
    }
    cout << (ok ? cnt : 0) << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
//5
//3 2 2 2 1
//1 2
//3 1
//4 1
//1 5
//:-> 1
