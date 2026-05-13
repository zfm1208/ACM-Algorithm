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
    int n, k; cin >> n >> k;
    map<int, int> mp;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        mp[x]++;
    }
    vector<int> v;
    for(auto &[x,y] : mp){
        v.push_back(x * y);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 0; i < max(0LL, (int)v.size() - k); i++){
        ans += v[i];
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