#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int seed = 131;
const int inf = 1e18;
const int N = 2e5 + 5;
int ha1[N],ha2[N];
int p1[N],p2[N];
void init(){
    p1[0] = p2[0] = 1;
    for(int i = 1; i < N; i++){
        p1[i] = p1[i-1] * seed % mod1;
        p2[i] = p2[i-1] * seed % mod1;
    }
}
void getha(string x){
    ha1[0] = ha2[0] = 0;
    for(int i = 1; i <= x.size(); i++){
        ha1[i] = (ha1[i-1] * seed % mod1 + x[i-1]) % mod1;
        ha2[i] = (ha2[i-1] * seed % mod2 + x[i-1]) % mod2;
    }
}
// 获取s[l,r]的哈希值,避免负数
int get1(int l,int r){
    return (ha1[r] - ha1[l-1] * p1[r - l + 1] % mod1 + mod1 ) % mod1;
}
int get2(int l,int r){
    return (ha2[r] - ha2[l-1] * p2[r - l + 1] % mod2 + mod2 ) % mod2;
}
pii getha(int l,int r){
    return {get1(l,r),get2(l,r)};
}
void solve() {
    init();
    string s; cin >> s;
    getha(s);
    pii ans = getha(4,6);
    cout << ans.first << ' ' << ans.second << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--) solve();
    return 0;
}
