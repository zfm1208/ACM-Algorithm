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

void solve() {
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    int ans = 0;
    int cnt1=0,d1=0;
    for(int i = 1; i <= n; i++){
        if(s[i] == '1'){
            cnt1++;
        }else{
            d1 += (cnt1+1)*cnt1/2;
            cnt1=0;
        }
    }
    d1 += (cnt1+1)*cnt1/2;
    ans += d1 * 0;
    int cnt0=0,d0=0;
    for(int i = 1; i <= n; i++){
        if(s[i] == '0'){
            cnt0++;
        }else{
            d0 += (cnt0+1)*cnt0/2;
            cnt0=0;
        }
    }
    d0 += (cnt0+1)*cnt0/2;    
    ans += d0 * 1;
    int tot = n * (n+1) / 2;
    tot -= d0;
    tot -= d1;
    ans += tot * 2;
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