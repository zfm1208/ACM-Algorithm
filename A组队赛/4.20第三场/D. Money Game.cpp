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
// https://qoj.ac/contest/1071/problem/5304
void solve(){
    int n; cin >> n;
    vector<double> a(n+1);
    double sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    double ans = sum * 1.0 / (n+1);
    for(int i = 1; i <= n; i++){
        if(i == 1) cout << fixed << setprecision(10) << 2 * ans << " ";
        else cout << ans << " ";
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