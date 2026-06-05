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
1. 如果用双指针判回文，第一次失败在哪里？
2. 第一次失败后，删除位置是不是只可能在两个端点？
3. 固定外层已经匹配了多少对，剩下中间块要满足什么？
4. “删左可行 or 删右可行”有没有重复？用容斥。
*/
void solve(){
    int n; cin >> n;
    int ans = 0;
    for(int i = 0; n - 2 * i >= 2; i++){
        int m = n - 2 * i;
        int res = 2 * 25 % mod * ksm(26, m / 2) % mod;
        if(m % 2 == 0){
            res = (res - 26 * 25 % mod + mod) % mod;
        }
        ans = (ans + ksm(26, i) * res) % mod;
    }
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