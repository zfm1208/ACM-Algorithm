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
int ksm(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
int fact[N];
int invfact[N];
void init(){
    fact[0] = 1;
    for(int i = 1; i <= N-1; i++){
        fact[i] = fact[i-1] * i % mod;
    }
    invfact[N-1] = ksm(fact[N-1],mod-2);
    for(int i = N-2; i >= 0; i--){
        invfact[i] = invfact[i+1] * (i+1) % mod;
    }
}
int C(int a, int b){
    if(a<b) return 0;
    return fact[a] * invfact[b] % mod * invfact[a-b] % mod;
}
/*
    sum = k*n + r
    前r个人操作k+1次
    后n-r个人操作k次
*/
void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    int sum = 0;
    for(int i = 0; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    int ans = 0;
    int k = sum / n;
    int sum1 = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] < k){
            sum1 += (k-a[i]);
        }
    }
    if(a[0] < sum1){
        cout << 0 << endl;
        return;
    }
    int shengyu = a[0] - sum1;
    int r = sum % n;
    // 充足cnt1 不充足cnt2
    int cnt1 = 0,cnt2 = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] > k) cnt1++;
        else cnt2++;
    }
    int mn = min(cnt2,shengyu);
    for(int i = 0; i <= mn; i++){
        int tp = C(cnt2,i) % mod * C(cnt1,r-i) % mod;
        ans = (ans + tp) % mod;
    }
    for(int i = 1; i <= r; i++){
        ans = ans * i % mod;
    }
    for(int i = 1; i <= (n-r); i++){
        ans = ans * i % mod;
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    init();
    cin >> T;
    while(T--)
        solve();
    return 0;
}