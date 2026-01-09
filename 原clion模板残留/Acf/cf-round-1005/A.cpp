//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define uint unsigned long long
#define pii pair<int,int>
#define int long long
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for(int i = 1; i < n; i++){
        if(s[i] != s[i - 1]) ans++;
    }
    if(s[0] == '1') ans++;
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
