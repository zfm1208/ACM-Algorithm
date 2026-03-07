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
int ksm(int a, int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a;
        b /= 2;
        a = a * a; 
    }
    return res;
}
/*
    可以暴力打表，也可以观察得到n^n % n肯定合法
    那么k和n的关系是?
    k是n的质因子之积
    假如n = a1 ^ k1 * a2 ^ k2 * a3 ^ k3
    n = 2^3 * 3^2 * 5^1 = 360
    k = 2 * 3 * 5 = 30
    
    (k^n) = 30 ^ 360 = 2 ^ 360 * 3 ^ 360 * 5 ^ 360
    (k^n) % n = 2 ^ 360 * 3 ^ 360 * 5 ^ 360 % (2^3 * 3^2 * 5^1)
    => 2^360 % 2^3  * 3^360 % 3^2  *  5^360  %  5^1
    == 0
    15 ^ 2 = 225
    25 * 9 = 225
    (a*b)^k = a^k * b^k
*/
void solve(){
    int n; cin >> n;
    int ans = 1;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            ans *= i;
            while(n % i == 0) n /= i;
        }
    }
    cout << ans * n << endl;
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