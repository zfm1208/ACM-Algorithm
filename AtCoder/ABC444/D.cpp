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
/*
      7 6 5 4 3 2 1
      1 1 1 1 1 1 1 
        1 1 1 1 1 1
        1 1 1 1 1 1
            1 1 1 1
          1 1 1 1 1
              1 1 1

      1 3 4 5  6  6  6

*/
void solve(){
    int n; cin >> n;
    int mx = 0;
    map<int,int> mp;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        mp[x]++;
        mx = max(mx,x);
    }
    vector<int> suf(mx+1000);
    for(int i = mx; i >= 1; i--){
        suf[i] = suf[i+1] + mp[i];
    }
    string ans;
    int jw = 0;
    for(int i = 1; i <= mx || jw > 0; i++){
        int op = jw + suf[i];
        ans += to_string(op % 10);
        jw = op / 10;
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}