//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

void solve() {
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    int q;cin >> q;
    if(n < 4) {
        int gty, zfm;
        while(q--){
            cin >> gty >> zfm;
            cout << "NO" << endl;
        }
        return ;
    }
    int cnt = 0;
    for(int i = 1; i <= n - 3; i++){
        if(s.substr(i,4) == "1100") cnt++;
    }
    int i;
    char x;
    while(q--){
        cin >> i >> x;
        if(s[i] != x)
        {
            for (int j = i - 4; j <= i; ++j){
                if (j >= 1 && j + 3 <= s.size()){
                    if (s.substr(j, 4) == "1100"){
                        --cnt;
                    }
                }
            }
            s[i] = x;
            for (int j = i - 4; j <= i; ++j){
                if (j >= 1 && j + 3 <= s.size()){
                    if (s.substr(j, 4) == "1100"){
                        ++cnt;
                    }
                }
            }
        }
        if(cnt >= 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
