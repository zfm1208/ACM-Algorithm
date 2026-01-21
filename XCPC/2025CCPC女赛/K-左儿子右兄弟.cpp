#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
double pi = acos(-1);
const int N = 1e5+7, mod = 998244353, inf = 1e18 + 5;
int n;
vector<int> e[N];
int cnt = 1,ans;
int fact[N];
int siz[N];
void dfs(int u){
    map<int,int> mp;
    vector<int> vc;
    siz[u] = 1;
    for(auto &v: e[u]){
        dfs(v);
        siz[u] += siz[v];
        mp[siz[v]]++;
        vc.push_back(siz[v]);
    }
    sort(vc.begin(), vc.end());
    int op = 0;
    for(auto &x: vc){
        op += x;
        ans += op;
    }
    ans++;
    for(auto &[_,y] :mp){
        cnt = cnt * fact[y] % mod;
    }
}
void solve() {
    fact[0] = 1;
    for(int i = 1; i < N; i++){
        fact[i] = fact[i-1] * i % mod;
    }
    cin >> n;
    for(int i = 2; i <= n; i++){
        int x; cin >> x;
        e[x].push_back(i);
    }
    dfs(1);
    cout << ans << endl << cnt << endl;;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}