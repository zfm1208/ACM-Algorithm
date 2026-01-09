//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 5;
int n,st,en;
vector<int> e[N];
int deep[N];
void dfs(int u,int fa){
    deep[u] = deep[fa] + 1;
    for(auto v:e[u]){
        if(v == fa) continue;
        dfs(v,u);
    }
}
void solve() {
    cin >> n >> st >> en;
    rep(i,1,n-1){
        int u,v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs(en,0);
    priority_queue<pii>q;
    rep(i,1,n) q.push({deep[i],i});
    rep(i,1,n){
        cout << q.top().second << " ";
        q.pop();
    }
    cout << endl;
    rep(i,1,n) e[i].clear();
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}