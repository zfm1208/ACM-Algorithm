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
const int N = 1e6, mod = 998244353, inf = 1e18 + 5;
void solve(){
    int n; cin >> n;
    vector<int> a(n+1),pre(n+1);
    for(int i = 1; i <= n ; i++){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    vector<int> suf(n+2,-inf);
    for(int i = n; i >= 1; i--){
        suf[i] = max(suf[i+1], i * i + i - pre[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans,suf[i] - (i * i - i - pre[i-1]));
    }
    cout << pre[n] + ans << endl;
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