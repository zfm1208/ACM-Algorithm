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
    int x,y;
    cin >> x >> y;
    int t = 0;
    for(int i = 60; i >= 0; i--)
    {
        if(((x>>i) & 1))
        {
            t = i + 1;
            break;
        }
    }
    int tt = (1ll << t) - 1;
    cout << 2 << '\n';
    cout << (x ^ tt) << ' ';
    cout << (y ^ tt) << '\n';
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