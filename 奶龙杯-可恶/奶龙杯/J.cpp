
#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define se second
#define fi first
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
void solve() {
    string s,t; cin >> s >> t;
    s = " " + s,t = " " + t;	
    int n = s.size(),m = t.size();
    // int m = t.size();
    // for(int i = 0; i <= m; i++){
    //     string tp = s.substr(0,i) + s.substr((int)s.size() - (m-i),m-i);
    //     bool ok = 0;
    //     for(int j = 0; j < m; j++){
    //         if(t[j] == tp[j] || t[j] == '?' || tp[j] == '?'){
    //         }else{
    //             ok = 1;
    //             cout << "No" << endl;
    //             break;
    //         }
    //     }
    //     if(!ok) cout << "Yes" << endl;
    // }
    vector<int> pre(m+10),suf(m+10);
    pre[1] = 1;
    for(int i = 1; i <= m; i++){
        if(s[i] == t[i] || s[i] == '?' || t[i] == '?') pre[i+1] = 1;
        else break;
    }
    for(int i = m; i >= 1; i--){
        if(s[n-m+i] == t[i] || s[n-m+i] == '?' || t[i] == '?') suf[i] = 1;
        else break;
    }
    for(int i = 1; i <= m; i++){
        if(pre[i] && suf[i]){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}   

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--)
        solve();
    return 0;
}