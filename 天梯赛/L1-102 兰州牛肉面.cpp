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
    vector<double> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int op,x;
    map<int,int>mp;
    double ans = 0;
    while(cin >> op >> x && (op != 0 && x != 0)){
        mp[op] += x;
        ans += a[op] * x;
    }
    for(int i = 1; i <= n; i++){
        cout << mp[i] << endl;
    }
    cout << fixed << setprecision(2) << ans;
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