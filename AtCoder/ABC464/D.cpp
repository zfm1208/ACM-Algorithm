#include<bits/stdc++.h>
using namespace std;
#define vii vector<int>
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;
    vii x(n+1), y(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> x[i];
    }
    for(int i = 1; i <= n - 1; i++){
        cin >> y[i];
    }
    vector<vii> dp(n+1,vii(2,-inf));
    if(s[1] == 'S'){
        dp[1][0] = 0;
        dp[1][1] = -x[1];
    }else{
        dp[1][0] = -x[1];
        dp[1][1] = 0;
    }
    for(int i = 2; i <= n; i++){
        for(int k = 0; k <= 1; k++){
            int val = dp[i - 1][0];
            if(k == 0){
                if(s[i] == 'R') val -= x[i];
            }else{
                if(s[i] == 'S') val -= x[i];
            }
            dp[i][k] = max(dp[i][k], val);
        }
        for(int k = 0; k <= 1; k++){
            int val = dp[i - 1][1];
            if(k == 0){
                if(s[i] == 'R') val -= x[i];
            }else{
                if(s[i] == 'S') val -= x[i];
            }
            if(k == 0){
                val += y[i - 1];
            }
            dp[i][k] = max(dp[i][k], val);
        }
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
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