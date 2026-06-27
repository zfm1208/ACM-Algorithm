#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define vii vector<int>
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<pii>> cun(m + 1);
    vii cnt(n + 1, 0);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int a, d, b;
        cin >> a >> d >> b;
        cun[d].pb({a, b});
        if(cnt[a] == 0) ans++;
        cnt[a]++;
    }
    // for(int i = 1; i <= n; i++){
    //     cout << "i: " << cnt[i] << endl;
    // }
    for(int i = 1; i <= m; i++){
        for(auto &[a, b] : cun[i]){
            if(a == b) continue;
            cnt[a]--;
            if(cnt[a] == 0) ans--;
            if(cnt[b] == 0) ans++;
            cnt[b]++;
        }
        cout << ans << endl;
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