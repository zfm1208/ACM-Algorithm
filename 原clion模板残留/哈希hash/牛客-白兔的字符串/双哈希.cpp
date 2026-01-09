#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int seed1 = 233;
const int seed2 = 13331;
const int N = 2e6 + 500;
ull ha1[N], ha2[N], p1[N], p2[N];
string t,s;
void init(){
    p1[0] = p2[0] = 1;
    for(int i = 1; i < N; i++){
        p1[i] = p1[i - 1] * seed1 % mod1;
        p2[i] = p2[i - 1] * seed2 % mod2;
    }
}
void solve(){
    init();
    cin >> t;
    int len1 = t.size();
    t = ' ' + t + t;
    int len2 = t.size();
    set<pair<ull, ull>> st;
    ha1[0] = ha2[0] = 0;
    for(int i = 1; i < len2; i++){
        ha1[i] = (ha1[i - 1] * seed1 + t[i] - 'a') % mod1;
        ha2[i] = (ha2[i - 1] * seed2 + t[i] - 'a') % mod2;
    }
    int j = 1;
    for(int i = len1; i < len2; i++){
        ull hash1 = (ha1[i] - ha1[j - 1] * p1[i - j + 1] % mod1 + mod1) % mod1;
        ull hash2 = (ha2[i] - ha2[j - 1] * p2[i - j + 1] % mod2 + mod2) % mod2;
        st.insert({hash1, hash2});
        j++;
    }
    int n; cin >> n;
    while(n--){
        cin >> s;
        s = ' ' + s;
        int cnt = 0;
        ha1[0] = ha2[0] = 0;
        int len = s.size();
        for(int i = 1; i < len; i++){
            ha1[i] = (ha1[i - 1] * seed1 + s[i] - 'a') % mod1;
            ha2[i] = (ha2[i - 1] * seed2 + s[i] - 'a') % mod2;
        }
        for(int i = len1; i < len; i++){
            int j = i - len1 + 1;
            ull hash1 = (ha1[i] - ha1[j - 1] * p1[len1] % mod1 + mod1) % mod1;
            ull hash2 = (ha2[i] - ha2[j - 1] * p2[len1] % mod2 + mod2) % mod2;
            if (st.count({hash1, hash2})) cnt++;
        }
        cout << cnt << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    while (T--) solve();
    return 0;
}