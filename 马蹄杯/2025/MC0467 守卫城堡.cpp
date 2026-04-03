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
    贪心策略+概率+乘法逆元

    我们从大到小排序，这样的话，他就只能从左到右去攻击，后面的不会收到影响
    然后计算当前礁石被攻击到的概率p， 期望就是1/p
    然后这一题的总期望E = 所有期望之和 = range (i,1,n)  1/pi
*/
void solve(){
    int n,m; cin >> n >> m;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a.begin()+1,a.end(),greater<int>());
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] <= m){
            ans = (ans + m * ksm(a[i],mod-2) % mod) % mod;
        }else{
            ans = (ans + 1) % mod;
        }
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