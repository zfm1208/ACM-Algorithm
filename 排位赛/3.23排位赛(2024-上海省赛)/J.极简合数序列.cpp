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
    vector<int> a(n+1),pre(n+1);
    rep(i,1,n) cin >> a[i],pre[i] = pre[i-1] + a[i];
    int ans = -1;
    auto check = [&](int x) -> bool {
        if(x <= 2) return true;
        bool ok = 0;
        for(int i = 2; i * i <= x; i++){
            if(x % i == 0) return false;
        }
        return true;
    };
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            int sum = pre[j] - pre[i-1];
            if(check(sum)) continue;
            if(ans == -1) ans = j-i;
            else ans = min(ans, j-i);
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