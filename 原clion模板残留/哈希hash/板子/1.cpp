#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
ull seed = 131; //种子，选择质数
ull p[N]; // 存储 p^i
ull ha[N]; // 存储前缀哈希值
// 初始化幂次数组
void init() {
    p[0] = 1;
    for(int i = 1; i <= N; i++){
        p[i] = p[i - 1] * seed;
    }
}
void haxi(string s){
    for(int i = 1; i <= s.size(); i++){
        ha[i] = ha[i - 1] * seed + s[i - 1];
    }
}
ull get(int l, int r){
    return ha[r] - ha[l - 1] * p[r - l + 1];
}
void solve() {
    init();
    string s = "abcdefg";
    haxi(s);
    ull ans = get(4,6);
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--) solve();
    return 0;
}
