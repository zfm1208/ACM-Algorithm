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

void solve(){
    int n, m, k; 
    cin >> n >> m >> k;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    int ans = -inf;
    vector<int> vis(n+1, 0);
    int cnt = (n - k) / m + 1; 
    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        vector<int> c;
        int now = i;
        while(vis[now] == 0){
            vis[now] = 1;
            c.pb(a[now]);
            now = (now - 1 + m) % n + 1; 
            // cout << "now: " << now << endl;
        }
        int len = c.size();
        for(int x: c) c.pb(x);
        int res = 0;
        for(int j = 0; j < cnt; j++){
            res += c[j];
        }
        ans = max(ans, res);
        for(int j = 1; j < len; j++){
            res = res - c[j - 1] + c[j + cnt - 1]; 
            ans = max(ans, res);
        }
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