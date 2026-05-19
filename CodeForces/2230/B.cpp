#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;

void solve(){
    string s; cin >> s;
    int n = s.size();
    int c4 = 0;
    for(auto c: s) if(c == '4') c4++;
    int ans = n;
    // 12  32
    vector<int> pre(n+2), suf(n+2);
    s = " " + s;
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i-1];
        if(s[i] == '1' || s[i] == '3') pre[i]++;
    }

    for(int i = n; i >= 1; i--){
        suf[i] = suf[i+1];
        if(s[i] == '2') suf[i]++;
    }
    for(int i = 0; i <= n; i++){
        ans = min(ans, pre[i] + suf[i+1] + c4);
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}