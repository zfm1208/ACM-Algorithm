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
    int n,x,y,z; cin >> n >> x >> y >> z;
    int ans = (n + x + y - 1) / ( x + y);
    if((n + x - 1) / x <= z){
        ans = min(ans, (n + x - 1) / x );
    }else{
        int op = n - z * x;
        int s1 = (op + x + 10 * y - 1) / (x + 10 * y);
        s1 += z;
        ans = min(ans, s1);
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