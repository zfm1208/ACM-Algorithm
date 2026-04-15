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
    int n,m,k; cin >> n >> m;
    for(; k <= n*m/2; k++){
        int x=0;
        int cnt=0;
        for(int i=1;i<=n*m;i++)
        {
            x+=n-1;
            if(min(x % (n*m), (n * m)- x % (n * m)) <= k) cnt++;
        }
        cout << k << " : " << cnt << endl;        
    }
    // int n,m,k; 
    // cin >> n >> m >> k;
    // if(k == n * m / 2){
    //     cout << n*m << '\n';
    //     return;
    // }
    // int gg=__gcd(n-1,m);
    // int ans=gg;
    // int l=k/gg;
    // ans+=l*2*gg;
    // cout << ans << '\n';

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