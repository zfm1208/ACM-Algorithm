#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int mod = 998244353;

void solve(){
    int n,m; cin >> n >> m;
    int ans = 0;
    vector<int> siz(n+1);
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        siz[u]++;
        siz[v]++;
    }
    map<int,int> mp;
    for(int i = 1; i <= n; i++){
        mp[siz[i]]++;
    }
    for(auto [x,cnt] : mp){
        for(auto [y,cnt1] : mp){
            if(x > y) continue;
            int temp = (x^y) % mod *(x|y) % mod * (x&y) % mod;
            ans = (ans + temp * cnt % mod * cnt1 % mod) % mod;
        }
    }
    cout << ans  << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}