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
    int tot = n * (n + 1) / 2;
    int cnt0 = 0; 
    int cnt1 = 0; 
    int len0 = 0;
    int len1 = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] == '0'){
            len0++;
            if(len1){
                cnt1 += len1 * (len1 + 1) / 2;
                len1 = 0;
            }
        }else if(s[i] == '1'){
            len1++;
            if(len0){
                cnt0 += len0 * (len0 + 1) / 2;
                len0 = 0;
            }
        }
    }
    cnt0 += len0 * (len0 + 1) / 2;
    cnt1 += len1 * (len1 + 1) / 2;
    int ans = 2 * tot - cnt0 - 2 * cnt1;
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