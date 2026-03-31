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
int cnt[N+3];
void solve(){
    int n,q; cin >> n >> q;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    while(q--){
        int l,r; cin >> l >> r;
        int mx = 0;
        rep(i,l,r){
            cnt[a[i]] = 0;
        }
        rep(i,l,r) {
            cnt[a[i]]++;
            mx = max(mx, cnt[a[i]]);
        }
        cout << mx << endl;
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