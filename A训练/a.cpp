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
    int n; cin >> n;
    vector<int> a(2*n+1);
    for(int i = 1; i <= 2 * n; i++) cin >> a[i];
    int p1 = 0, p2 = 0;
    rep(i, 1, 2 * n){
        if(a[i] == 0){
            if (p1 == 0) p1 = i;
            else p2 = i;
        }
    }
    int ans = 1;
    vector<pii> res;
    res.pb({p1,p1});
    res.pb({p2,p2});
    bool ok = 1;
    int l = p1,r = p2;
    while(l < r){
        if(a[l] != a[r]){
            ok = 0;
            break;
        }
        l++,r--;
    }
    if(ok) res.pb({p1,p2});
    for(auto [l,r] : res){
        while(l > 1 && r < 2*n && a[l-1] == a[r+1]){
            l--;
            r++;
        }
        vector<int> vis(n+1);
        for(int i = l; i <= r; i++){
            vis[a[i]] = 1;
        }
        int op = 0;
        while(op <= n && vis[op]) op++;
        ans = max(ans, op);
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