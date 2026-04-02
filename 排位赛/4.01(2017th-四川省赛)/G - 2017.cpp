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
    int a,b,c,d;
    // x [a,b]  y[c,d]
    // x * y % 2017 == 0
    // count of pair{x,y}
    while(cin >> a >> b >> c >> d){
        if(b < 2017 && d < 2017) cout << 0 << endl;
        else{
            int ans = 0;
            ans += ((b/2017) - (a/2017) + (a % 2017 == 0)) * (d-c+1);
            ans += ((d/2017) - (c/2017) + (c % 2017 == 0)) * (b-a+1);
            ans -= ((b/2017) - (a/2017) + (a % 2017 == 0)) * ((d/2017) - (c/2017) + (c % 2017 == 0));
            cout << ans << endl;
        }
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