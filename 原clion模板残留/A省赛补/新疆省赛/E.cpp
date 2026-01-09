#include<bits/stdc++.h>
using namespace  std;
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pii pair<int,int>
#define fi first
#define se second
void solve(){
    int n; cin >> n;
    vector<pii> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }
    int mx = 0;
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        int u = a[i].fi,v=a[i].se;
        if (mx >= max(u, v)) ans += mx - min(u, v);
        else {
            if (u < v) ans += v - u;// 上午买入 当天下午卖出 仍有利润贡献
            else if (mx > min(u,v)) ans += mx - v;
            mx = max(u, v);
        }
    }
    cout << ans;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}