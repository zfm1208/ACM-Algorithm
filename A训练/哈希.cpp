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
const int base = 13331;
void solve(){
    string s; cin >> s;
    int n = s.length();
    s = " "  + s;
    vector<int> hs(n+2),hsf(n+2),p(n+2);
    p[0] = 1;
    for(int i = 1; i <= n; i++){
        p[i] = p[i-1] * base % mod;
        hs[i] = (hs[i-1] * base + s[i]) % mod;
    }
    hsf[n+1] = 0;
    for(int i = n; i >= 1; i--){
        hsf[i] = (hsf[i+1] * base + s[i]) % mod;
    }
    int l = 1, r = n;
    while(l < r && s[l] == s[r]){
        l++;
        r--;
    }
    if(l >= r){
        cout << "1 1\n";
        return;
    }
    auto get_hash = [&] (int l, int r) -> int {
        int res = (hs[r] - hs[l-1] * p[r-l+1] % mod + mod) % mod;
        return res;
    };

    auto get_hashf = [&] (int l, int r) -> int {
        int res = (hsf[l] - hsf[r+1] * p[r-l+1] % mod + mod) % mod;
        return res;
    };
    // 交换区间[l,i]
    for(int i = l; i < r; i++){
        if(s[i] != s[r]) continue;
        int hs1 = (get_hashf(l,i) * p[r-i] % mod + get_hash(i+1,r)) % mod;
        int hs2 = (get_hashf(i+1,r) * p[i-l+1] % mod + get_hash(l,i)) % mod;
        if(hs1 == hs2){
            cout << l << " " << i << endl;
            return;
        }
    }
    // 交换区间[i,r]
    for(int i = l+1; i <= r; i++){
        if(s[i] != s[l]) continue;
        int hs1 = (get_hash(l,i-1) * p[r-i+1] % mod + get_hashf(i,r)) % mod;
        int hs2 = (get_hash(i,r) * p[i-l] % mod +get_hashf(l,i-1)) % mod;
        if(hs1 == hs2){
            cout << i << " " << r << endl;
            return;
        }
    }
    cout << -1 << " " << -1 << endl;

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}