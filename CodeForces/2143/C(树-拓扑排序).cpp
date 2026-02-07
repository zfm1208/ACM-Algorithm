#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define ull unsigned long long
#define piii pair<int, pair<int, int>>
#define pii pair<int, int>
#define int long long
#define ld long double
#define pb push_back
#define se second
#define fi first
double pi = acos(-1);
const int mod = 1e9 + 7, mod1 = 998244353, inf = 1e18 + 5;
const int N = 2e5 + 10;
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n+1);
    vector<int> du(n+1);
    vector<int> ans(n+1);
    for(int i = 1; i < n; i++){
        int u,v,x,y; cin >> u >> v >> x >> y;
        if(x > y){
            a[u].pb(v);
            du[v]++;
        }else{
            a[v].pb(u);
            du[u]++;
        }
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(!du[i]) q.push(i);
    }
    int fill = n;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        ans[u] = fill--;
        for(auto v: a[u]){
            if(--du[v] == 0){
                q.push(v);
            }
        }
    }
    rep(i,1,n) cout << ans[i] << " \n"[i == n];
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}