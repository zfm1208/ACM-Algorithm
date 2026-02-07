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
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    bool ok = 0;
    for(int i = 0; i < n - 1; i++){
        if(s[i] > s[i+1]){
            ok = 1;
            break;
        }
    }
    if(ok == 0){cout << "Bob" << endl; return;}
    int cnt = 0;
    for(auto c: s) if(c == '0') cnt++;
    s = " " + s;
    vector<int> ans;
    for(int i = 1; i <= cnt; i++){
        if(s[i] == '1') {
            ans.pb(i);
        }
    }
    for(int i = cnt + 1; i <= n; i++){
        if(s[i] == '0') ans.pb(i);
    }
    cout << "Alice" << endl;
    cout << ans.size() << endl;
    for(auto x: ans) cout << x << " ";
    cout << endl;
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