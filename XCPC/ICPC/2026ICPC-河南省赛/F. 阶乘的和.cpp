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
const int N = 1e6, mod = 10000, inf = 1e18 + 5;

void solve(){
    int n; cin >> n;
    int ans = 0;
    int op = 1;
    for(int i = 1; i <= min(n, 10000LL); i++){
        op = op * i % mod;
        ans = (ans + op) % mod;
    }
    cout << ans << endl;
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