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
const int N = 1e6, mod = 1e9+7, inf = 2e18 + 5;
#define i128  __int128_t
/*
    gcd * lcm = a1 *a2 * ... * an
    lcm (a,b) = a / (gcd(a,b)) * b

    不难推出
    x(x+1) = k * 2 * lcm
    直接枚举x/k会超时
    我们观察到左式 x x+1
    __gcd(x,x+1) = 1
    2 * lcm = p1 ^ k1 * p2 ^ k2 * ... * pn ^ kn
    把 2 * lcm 拆成 多个质数块
    把这些质数 分成 两部分
    即为 A，B ，那么显然 A * B = 2 * lcm
    则 x 是 A的倍数, x+1 是 B 的倍数

    x = y * A (y 是 未知倍数)
    y * A  + 1 是 B 的倍数
    y * A % B = -1      <1>

    只要我们算出来 y, 再乘以A, X 就能算出来了

    exGCD :
    u * A + v * B  = 1 (A,B 互质, __gcd(A,B) = 1)
    两边对B取模
    u * A % B = 1       <2>

    <1> <2> 这两个式子很像
    y = -u
    x = y * A = -u * A


*/
int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    map<int,int> mp;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        for(int j = 2; j * j <= a[i]; j++){
            if(a[i] % j == 0){
                int cnt = 0;
                while(a[i] % j == 0){
                    cnt++;
                    a[i] /= j;
                }
                mp[j] = max(mp[j], cnt);
            }
        }
        if(a[i] > 1) mp[a[i]] = max(mp[a[i]], 1LL);
    }
    mp[2]++;
    vector<int> block;
    for(auto [prime, e] : mp){
        int cur = 1;
        for(int i = 1; i <= e; i++) cur *= prime;
        block.pb(cur);
    }
    int ans = inf << 1;
    int k = block.size();
    for(int msk = 0; msk < (1LL << k); msk++){
        int A = 1,B = 1;
        for(int i = 0; i < k; i++){
            if((msk >> i) & 1LL){
                A *= block[i];
            }else B *= block[i];
        }
        int u,v;
        exgcd(A,B,u,v);
        int y = (-u % B + B) % B;
        i128 x = (i128)y * A;
        if(x == 0LL) x = (i128) A * B;
        if(x < ans) ans = (int)x;
    }
    cout << ans << endl;
    // i128 lcm = 1;
    // for(int i = 1; i <= n; i++){
    //     cin >> a[i];
    //     lcm = lcm / (__gcd((int)lcm,a[i])) * a[i];
    // }
    // // op = k * lcm
    // // ans * (ans + 1) / 2 == op
    // auto sqrt128 = [&] (i128 n) -> i128 {
    //     i128 l = 1,r = inf;
    //     i128 ans = 1;
    //     while(l <= r){
    //         i128 mid = (l + r) / 2;
    //         if(mid * mid <= n){
    //             ans = mid;
    //             l = mid + 1;
    //         }else{
    //             r = mid - 1;
    //         }
    //     }
    //     return ans;
    // };
    // for(int k = 1;; k++){
    //     i128 cur = 2 * k * lcm;
    //     i128 ans = sqrt128(cur);
    //     if(ans * (ans + 1) == cur){
    //         cout << (int)ans << endl;
    //         return;
    //     }
    // }
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