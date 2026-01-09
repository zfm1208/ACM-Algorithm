//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    bool flag = 0;
    for(int i = 0 ; i < n; i ++){
        for(int j = 0; j < n; j ++){
            if(s[i] == 's' && s[j] == 'p' && i != 0 && j != (n - 1)){
                flag = 1;
                break;
            }
        }
        if(flag)break;
    }
    if(flag)cout << "NO" << endl;
    else cout << "YES" << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
