#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
int ans,v,n;
void solve() {
    string s;
    cin >> n >> s;
    s= ' ' + s;
    int p = -1;
    int v1 = 0;
    bool f = false;
    for(int i = 1; i <= n; ++i){
        if(p == i -1){
            if(f) v += v1;
            else v += 10;
            f= false;
            v1 = 0;
            p = -1;
        }
        if(s[i] == '0'){
            v += 10;
        }else if(s[i] == '1'){
            v = max(v - 5, 0ll);
        }else if(s[i] == '2'){
            v1 = v;
            v = max(v - 10, 0ll);
            p = i;
            if(v==0) f = true;
        }
        ans += v;
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}
