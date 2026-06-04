#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define vii vector<int>
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
/*
    i: 1 0
    i: 2 1
    i: 3 01
    i: 4 101
    i: 5 01101
    i: 6 10101101
    i: 7 0110110101101
    i: 8 101011010110110101101
    i: 9 0110110101101101011010110110101101
    i: 10 1010110101101101011010110110101101101011010110110101101
    i: 11 01101101011011010110101101101011011010110101101101011010110110101101101011010110110101101

    i 1 0
    i 2 0
    i 3 0
    i 4 1
    i 5 2
    i 6 7
    i 7 18
    i 8 50
    i 9 132
    i 10 351
    i 11 924
    i 12 2431
    i 13 6380
    i 14 16732
    i 15 43848
    i 16 114869
    i 17 300846
    i 18 787815
    i 19 2062830
    i 20 5401054
*/
void solve(){
    // vector<string> s(n+1);
    // s[1] = "0";
    // s[2] = "1";
    // for(int i = 3; i <= n; i++){
    //     s[i] = s[i-2] + s[i-1];
    // }
    // rep(i,1,n) cout << "i: " << i << " " << s[i] << endl;
    // vii ans(n+1);
    // ans[1] = 0;
    // ans[2] = 0;
    // for(int i = 1; i <= n; i++){
    //     string S = s[i];
    //     for(int j = 0; j < S.size(); j++){
    //         for(int k = 0; k < j; k++){
    //             if(S[k] == '1' && S[j] == '0') ans[i]++;
    //         }
    //     }
    //     cout << "i " << i << " " << ans[i] << endl;
    // }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    int n = 1e5+10;
    vii cnt0(n+1), cnt1(n+1), dp(n+1);
    cnt0[1] = 1, cnt1[1] = 0;
    cnt0[2] = 0, cnt1[2] = 1;
    dp[1] = dp[2] = 0;
    for(int i = 3; i <= n; i++){
        cnt0[i] = (cnt0[i-2] + cnt0[i-1]) % mod;
        cnt1[i] = (cnt1[i-2] + cnt1[i-1]) % mod;
        dp[i] = ((dp[i-1] + dp[i-2]) % mod + cnt1[i-2] * cnt0[i-1] % mod) % mod;
    }
    cin >> T;
    while(T--){
        int nn; cin >> nn;
        cout << dp[nn] << endl;
    }

    return 0;
}