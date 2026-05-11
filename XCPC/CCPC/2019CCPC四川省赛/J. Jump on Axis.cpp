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
    一直选1： 1,4,7,10,...
    一直选2： 2,5,8,11,...
    一直选3： 3,6,9,12,...
    1 使用了a次, 2 使用了b次, 3 使用了c次
    sum_a = a(3a-1)/2
    sum_b = b(3b+1)/2
    sum_c = 3c(c+1)/2
    sum_a + sum_b + sum_c == k
    cnt = a+b+c
*/
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
int fact[N], inv[N];
vector<int> aa,bb,cc;
void init() {
    fact[0] = inv[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % mod;
    inv[N - 1] = ksm(fact[N - 1], mod - 2);
    for (int i = N - 2; i >= 1; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
    int mx = 1e7;
    for(int i = 0; i * (3 * i - 1) / 2 <= mx; i++){
        aa.push_back(i * (3 * i - 1) / 2);
    }
    for(int i = 0; i * (3 * i + 1) / 2 <= mx; i++){
        bb.push_back(i * (3 * i + 1) / 2);
    }
    for(int i = 0; 3 * i * (i + 1) / 2 <= mx; i++){
        cc.push_back(3 * i * (i + 1) / 2);
    }
}

int C(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fact[n] * inv[m] % mod * inv[n - m] % mod;
}

int op;
void solve(){
    int k; cin >> k;
    int mn = inf, tot = 0;
    for(int i = 0; i < aa.size(); i++){ // i 次选项 1
        if(aa[i] > k) break;
        for(int j = 0; j < bb.size(); j++){ // j 次选项 2
            if(aa[i] + bb[j] > k) break;
            int rem = k - aa[i] - bb[j];
            auto it = lower_bound(cc.begin(), cc.end(), rem);
            if(it != cc.end() && *it == rem){
                int z = it - cc.begin(); // z 次选项 3
                int step = i + j + z;
                mn = min(mn, step);
                int tp = C(step, i) * C(step - i, j) % mod;
                tot = (tot + tp) % mod;
            }
        }
    }
    cout << "Case " << ++op << ": "  << mn << " " << tot << endl;
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