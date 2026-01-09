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
#define eb emplace_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
const long double pi = acos(-1);
const int mod1 = 1e9 + 7,mod2 = 998244853,inf = 0x3f3f3f3f;
const int N = 3e5 + 5;
int n,m,k;
int ksm(int a, int b, int mod){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        b /= 2;
        a = a * a % mod;
    }
    return res;
}
void solve() {
    cin >> n >> m >> k;
    vector<vector<pii>> edge(N);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].pb({v, w});
        edge[v].pb({u, w});
    }
    vector<int> a(k + 1);
    for (int i = 1; i <= k; i++) cin >> a[i];
    int ans = 0;
    for(int i = 1; i < k; i++){
        int u = a[i], v = a[i + 1];
        int cnt = 0, sum = 0;
        for(auto& [next , w] : edge[u]){
            if(next == v){
                cnt++,sum += w;
            }
        }
        if(cnt == 0){
            cout << "Stupid Msacywy!" << endl;
            return;
        }
        int now = ksm(cnt,mod2 - 2, mod2);
        ans = (ans * 10 + sum * now % mod2) % mod2;
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--) solve();
//    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}