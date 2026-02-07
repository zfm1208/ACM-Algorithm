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
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

// 按位或OR 有1为1

/*
    t = 0
    an = [n]
    t = 1
    an = [n-1 ~ n+1]
    t = 2
    an = [n-2 ~ n+2]

           n-3                   n-2                 n-1               n              n+1                 n+2

    (n-4 | n-3 | n-2 )    (n-3 | n-2 | n-1)   (n-2 | n-1 | n)   (n-1 | n | n+1)  (n | n+1 | n+2)   (n+1 | n+2 | n+3)

    x | x = x

*/
void solve(){
    int n,m; cin >> n >> m;
    int L = max(0LL, n-m);
    int R = n+m;
    int cnt = 0;
    while(L != R){
        L >>= 1;
        R >>= 1;
        cnt++;
    }
    int ans = (L << cnt) + ((1LL << cnt) - 1);
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