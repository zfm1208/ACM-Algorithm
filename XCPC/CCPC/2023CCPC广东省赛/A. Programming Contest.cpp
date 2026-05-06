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
    int st; cin >> st;
    map<int,int> mp;
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        mp[x]++;
    }
    int ans = 0;
    int ed; cin >> ed;
    for(int i = st; i <= ed; i++){
        if(mp[i] == 0) ans++;
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