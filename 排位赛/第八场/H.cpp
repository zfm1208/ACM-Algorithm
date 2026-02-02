#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define rep(i,l,r) for(int i = l; i <= r; i++)
const int N = 2e5+9, mod = 1e9+7;

void solve(){
    int n,m; cin >> n >> m;
    map<string,int> mp;
    for(int i = 1; i <= m; i++){
        char c; cin >> c;
        string s; cin >> s;
        mp[s]++;
    }
    string s; cin >> s;
    s = ' ' + s;
    vector<int> dp(n+1),tp(n+1);
    tp[0] = dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int k = 1; k <= 5; k++){
            if(i < k) continue;
            if(mp.count(s.substr(i-k+1,k))){
                if(tp[i] + tp[i-k] * mp[s.substr(i-k+1,k)] >= 2){
                    tp[i] = 2;
                }else if(tp[i] + tp[i-k] * mp[s.substr(i-k+1,k)] == 1){
                    tp[i] = 1;
                }else{
                    tp[i] = 0;
                }
                dp[i] = (dp[i] + dp[i-k] * mp[s.substr(i-k+1,k)]) % 128;
            }
        }
    }
    if(tp[n] == 1){
        cout << "happymorsecode" << endl;
    }else if(tp[n] == 0) {
        cout << "nonono" << endl;
    }else{
        cout << "puppymousecat " << dp[n] << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}