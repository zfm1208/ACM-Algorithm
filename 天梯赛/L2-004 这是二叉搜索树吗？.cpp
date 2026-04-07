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
/*
    前中后序 遍历
    是指根什么时候遍历

    前序 ： 根 左 右
    后续 ： 左 右 后
*/
void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    vector<int> ans;
    auto dfs = [&](auto& self, int l, int r, bool ok) -> bool {
        if(l > r) return true;
        int root = a[l];
        int p = l + 1;
        if(ok) {
            while(p <= r && a[p] < root) p++;
            for(int i = p; i <= r; i++) if(a[i] < root)
                return false;
        }else{
            while(p <= r && a[p] >= root) p++;
            for(int i = p; i <= r; i++) if(a[i] >= root)
                return false;
        }
        bool L_ok = self(self, l+1, p-1, ok);
        bool R_ok = self(self, p, r, ok);
        if(L_ok && R_ok){
            ans.pb(root);
            return true;
        }
        return false;
    };
    if(dfs(dfs, 1, n, true)) {
        cout << "YES" << endl;
        for(int i = 0; i < n; i++){
            cout << ans[i] << (i == n-1 ? "" : " ");
        }
        ans.clear();
    }else if(dfs(dfs, 1, n, false)) {
        cout << "YES" << endl;
        for(int i = 0; i < n; i++){
            cout << ans[i] << (i == n-1 ? "" : " ");
        }
    }else{
        cout << "NO" << endl;
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