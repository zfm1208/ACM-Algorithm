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
/*
    b * gcd(a,b) 是 b 的倍数
    由 b * gcd(a,b) 是 a+b 的倍数
    所以 a+b 是 b 的倍数
    所以 a 是 b 的倍数
    所以 gcd(a,b) = b
    所以原式 ==>  a+b = x * b * b (x正整数)
    所以枚举b
    a = x * b * b - b
    a <= n
    max(x) = (n+b) / (b*b)
*/
void solve(){
    int n,m; cin >> n >> m;
    int ans = n;
    for(int b = 2; b <= m; b++){
        ans += (n + b) / (b * b);
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