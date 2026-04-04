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
    int n,m,k; cin >> n >> m >> k;
    vector<int> a(n+1);
    map<int,int> mp;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mp[i % m] += a[i];
    }
    int mx = mp[k % m];
    for(int i = 1; i <= n; i++){
        mp[i % m] -= a[i];
        mp[(n+i) % m] += a[i];
        mx = max(mx, mp[(k+i) % m]);
    }
    cout << mx << endl;
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