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
void solve1(){
    vector<string> s(3);
    cin >> s[1] >> s[2];
    int n = s[1].size();
    s[2] = ' ' + s[2];
    s[1] = ' ' + s[1];
    int L = -1, R = -1;
    for(int i = 1; i <= n; i++){
        if(s[1][i] == '#' || s[2][i] == '#'){
            if(L == -1) L = i;
            R = i;
        }
    }
    if(L == -1){cout << 0 << endl; return;}
    vector<vector<int>> dp(n+1,vector<int>(3,inf));
    if(s[2][L] != '#') dp[L][0] = s[1][L] != '#';
    if(s[1][L] != '#') dp[L][1] = s[2][L] != '#';
    dp[L][2] = (s[1][L] != '#') + (s[2][L] != '#');
    for(int i = L+1; i <= R; i++){
        int cost0 = (s[1][i] != '#');
        int cost1 = (s[2][i] != '#');
        int cost2 = cost0 + cost1;
        if(s[2][i] != '#') {
            dp[i][0] = min(dp[i-1][0], dp[i-1][2]) + cost0;
        }
        if(s[1][i] != '#') {
            dp[i][1] = min(dp[i-1][1], dp[i-1][2]) + cost1;
        }
        dp[i][2] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2]}) + cost2;
    }
    cout << min({dp[R][0], dp[R][1], dp[R][2]}) << endl;
}
void solve(){
    vector<string> s(3);
    cin >> s[1] >> s[2];
    int n = s[1].size();
    s[2] = ' ' + s[2];
    s[1] = ' ' + s[1];
    vector<pair<array<int,3>,array<int,3>>> ans;
    for(int i = 1;i <= n; i++){
        if(s[1][i] == '.' && s[2][i] == '.') continue;
        int l = i;int r = i;
        for(int j = i+1;j <= n; j++){
            if(s[1][j-1] == '#' && s[1][j] == '#'){r = j;}
            else if(s[2][j-1] == '#' && s[2][j] == '#'){r = j;}
            else{ break;}
        }
        int l1 = (s[1][l] == '#') ? 1 : 0;
        int l2 = (s[2][l] == '#') ? 1 : 0;
        int r1 = (s[1][r] == '#') ? 1 : 0;
        int r2 = (s[2][r] == '#') ? 1 : 0;
        ans.push_back({{l,l1,l2},{r,r1,r2}});
        i = r;
    }
    int nn = ans.size();
    if(nn <= 1){ cout << 0 << endl; return;}
    int cnt = 0;
    auto [l0,l1,l2] = ans[0].se;
    for(int i = 1; i < nn; i++){
        auto[r0,r1,r2] = ans[i].fi;
        cnt += r0-l0-1;
        if(r1 == 1 && l1 == 1){}
        else if(r2 == 1 && l2 == 1){}
        else{
            cnt++;
            if(r0 == ans[i].se[0]){
                ans[i].se[1] = 1;
                ans[i].se[2] = 1;
            }
        }
        l0 = ans[i].se[0];
        l1 = ans[i].se[1];
        l2 = ans[i].se[2];
    }
    cout << cnt << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve1();
    return 0;
}