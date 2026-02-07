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
//202026
void solve(){
    int n; cin >> n;
    string s;
    cin >> s;
    int ans1 = inf;
    string t = "2026";
    for(int i = 0; i <= n - 4; i++){
        int cnt = 0;
        for(int j = 0; j < 4; j++){
            if(s[i + j] != t[j]) cnt++;
        }
        ans1 = min(ans1, cnt);
    }
    int ans2 = 0;
    for(int i = 0; i <= n - 4; i++){
        if(s.substr(i, 4) == "2025"){
            ans2++;
        }
    }
    cout << min(ans1,ans2) << endl;
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