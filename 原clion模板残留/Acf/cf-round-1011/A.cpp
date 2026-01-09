//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define per(i,l,r) for(int i = l; i >= r; i--)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
const int mod1 = 1e9 + 7,mod2 = 998244353,inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

void solve() {
//    int n,k; cin >> n >> k;
//    string s; cin >> s;
//    s = " " + s;
//    int cnt = 0;
//    for(int i = 1; i < n; i++){
//        if(s[i] == s[i + 1])cnt++;
//    }
//    if(cnt == n-1){cout << "NO" << endl; return;}
//    if(n == 1){cout << "NO" << endl; return;}
//    if(k == 0){
//        if(s[1] < s[n]){cout << "YES" << endl; return;}
//        cout << "NO" << endl;
//        return;
//    }
//    cout << "YES" << endl;
    int n, k;cin >> n >> k;
    string s;cin >> s;
    string s1 = s;
    reverse(s1.begin(), s1.end());
    if(s < s1){
        cout << "YES" << endl;
        return;
    }
    if(s == s1){
        bool ok = true;
        for(int i = 1; i < n; i++){
            if(s[i] != s[0]){
                ok = false;
                break;
            }
        }
        if(ok)cout << "NO" << endl;
        else cout << (k >= 1 ? "YES" : "NO") << endl;
        return;
    }
    cout << (k >= 1 ? "YES" : "NO") << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
