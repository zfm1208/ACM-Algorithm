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
    int n; cin >> n;
    vector<int> a(n+1), b(n+1), pre1(n+1), pre2(n+1);
    rep(i, 1, n) cin >> a[i], pre1[i] = pre1[i-1] + a[i];
    rep(i, 1, n) cin >> b[i], pre2[i] = pre2[i-1] + b[i];
    int sum = 0;
    for(int i = 1; i <= n; i++){
        int x = pre2[i] - pre1[i];
        // cout << x << endl;
        if(x < 0){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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