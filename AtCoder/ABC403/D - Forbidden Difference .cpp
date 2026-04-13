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
    int n,d; cin >> n >> d;
    vector<int> a(n+1);
    map<int,int> mp;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    if(d == 0){
        set<int> s(a.begin()+1,a.end());
        cout << n - s.size() << endl;
        return;
    }
    int mx = *max_element(a.begin()+1,a.end());
    vector<vector<int>> dp(mx+1, vector<int>(2));
    for(int i = 0; i <= mx; i++){
        if(i < d){
            dp[i][0] = 0;
            dp[i][1] = mp[i];
        }else{
            dp[i][0] = max(dp[i - d][0], dp[i - d][1]);
            dp[i][1] = dp[i - d][0] + mp[i];
        }
    }
    int cnt = 0;
    int st = max(0LL, mx - d + 1);
    for(int i = st; i <= mx; i++){
        cnt += max(dp[i][0], dp[i][1]);
    }
    cout << n - cnt << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}