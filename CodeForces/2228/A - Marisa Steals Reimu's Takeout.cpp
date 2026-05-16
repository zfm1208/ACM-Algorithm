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
    int c0=0,c1=0,c2=0;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(x == 1) c1++;
        else if(x == 0) c0++;
        else c2++;
    }
    int ans = c0 + min(c1,c2);
    int mn = min(c1,c2);
    c1 -= mn;
    c2 -= mn;
    ans += c1/3 + c2/3;
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