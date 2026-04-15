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
/*

5 5
K: 0 : 1
K: 1 : 3
K: 2 : 5
K: 3 : 7
K: 4 : 9
K: 5 : 11
K: 6 : 13
K: 7 : 15
K: 8 : 17
K: 9 : 19
K: 10 : 21
K: 11 : 23
K: 12 : 25

5 6
K: 0 : 2
K: 1 : 2
K: 2 : 6
K: 3 : 6
K: 4 : 10
K: 5 : 10
K: 6 : 14
K: 7 : 14
K: 8 : 18
K: 9 : 18
K: 10 : 22
K: 11 : 22
K: 12 : 26
K: 13 : 26
K: 14 : 30
K: 15 : 30

5 8
K: 0 : 4
K: 1 : 4
K: 2 : 4
K: 3 : 4
K: 4 : 12
K: 5 : 12
K: 6 : 12
K: 7 : 12
K: 8 : 20  4 * 5 = 4 *  (2 * (8 / 4)  + 1)
K: 9 : 20
K: 10 : 20
K: 11 : 20
K: 12 : 28 4 * 7 = 4 * （2 * (12 / 4) + 1)
K: 13 : 28
K: 14 : 28
K: 15 : 28
K: 16 : 36 4 * 9 = 4 *  (2 * (16 / 4) + 1)
K: 17 : 36
K: 18 : 36
K: 19 : 36
K: 20 : 40

*/
void solve(){
    // int n,m; cin >> n >> m;
    // for(int k = 0; k <= n*m/2; k++){
    //     int x=0;
    //     int cnt=0;
    //     for(int i=1;i<=n*m;i++)
    //     {
    //         x+=n-1;
    //         if(min(x % (n*m), (n * m)- x % (n * m)) <= k) cnt++;
    //     }
    //     cout << "K: " << k << " : " << cnt << endl;        
    // }
    int n,m,k; 
    cin >> n >> m >> k;
    if(k == n * m / 2){
        cout << n*m << '\n';
        return;
    }
    int gg =__gcd(n-1,m);
    int ans = gg;
    ans += k/gg * 2 * gg;
    cout << ans << '\n';

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