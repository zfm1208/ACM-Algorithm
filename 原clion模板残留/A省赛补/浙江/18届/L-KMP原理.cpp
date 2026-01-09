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
#define eb emplace_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
const long double PI = acos(-1);
const int mod1 = 1e9 + 7,mod2 = 998244353,inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
void solve() {
//    int j = 1, ans  =0;
//    string s,t;
//    cin >> s >> t;
//    int n = s.size(),m = t.size();
//    s = " " + s;
//    t = " " + t;
//    for(int i = 1; i<= n; i++){
//        if(s[i] != t[j]) j=1; //如果匹配失败，则重置为1  这里是不对的  kmp是跳到next[]里面
//        if(s[i] == t[j]) j ++;
//        if(j>m){
//            ans++;
//            j = 1;
//        }
//    }
//    cout << ans << endl;
    int n; cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    int ok = 0;
    for(int i = 2; i <= n; i++){
        if(s[i] == s[1]){
            ok =1;
            break;
        }
    }
    if(ok == 1)cout << "Wrong Answer" << endl;
    else cout << "Correct" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--) solve();
//    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}