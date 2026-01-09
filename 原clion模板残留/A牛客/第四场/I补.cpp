#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
void solve() {
    int n;string s; cin >> n >> s;
    s=" "+s;
    vector<int> sum(n+5,0);

    for(int i = 1; i <= n; i++){
        sum[i] = sum[i-1] + (s[i] == 'u');
    }
    int ans = 0;
    for(int i = 3; i <= n; i++){
        if(i + 7 > n) break;
        string s1 = s.substr(i,8);
        if(s1 == "uwawauwa"){
            ans += sum[i-2];
        }
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
