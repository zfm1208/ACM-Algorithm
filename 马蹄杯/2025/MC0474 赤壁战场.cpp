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
const int N = 1e6, mod = 998244353, inf = 1e18 + 5;
int ksm(int a, int b) {
    int res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
/*
    该串都是小写英文字母
    还必须包含a,b,c
    长度为n
    求有多少种

    考虑容斥原理
    使用说有小写字母组合的情况
     ksm(26,n)
    不使用a,b,c，其中一个字母的组合情况
    3 * ksm(25,n)
    不使用a,b,c，其中2个字母的组合情况
    3 * ksm(24,n)
    不使用a,b,c，的组合情况
     ksm(24,n)

     ans = ksm(26,n) - 3 * ksm(25,n) + 3 * ksm(24,n) - ksm(24,n)
*/
void solve(){
    int n; cin >> n;
    if(n < 3){
        cout << 0 << endl;
        return;
    }
    int ans = (((ksm(26,n) - 3 * ksm(25,n) % mod + mod) % mod + 3 * ksm(24,n) % mod) % mod - ksm(23,n) % mod + mod) % mod;
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