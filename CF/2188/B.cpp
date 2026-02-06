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
    00010010
    ->01010010

    00010000010000
    ->01010101010010

    000000000
    ->010010010

    00000
    -> 01001

    000000
    -> 010010

    0000001....
    填充100
    ..0010000000100...
    
*/
void solve(){
    int n; cin >> n;
    string s; cin >> s;
    s = ' ' + s;
    int ans = 0;
    int cnt = 0;
    bool ok = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] == '1'){
            ans++;
            if(ok == 0){ // 第一个1
                ans += (cnt - 1 + 2) / 3;
            }else{
                ans += cnt / 3;
            }
            ok = 1;
            cnt = 0;
        }else{
            cnt++;
        }
    }
    if(ok == 0){
        ans += (n + 2) / 3;
    }else{
        ans += (cnt - 1 + 2) / 3;
    }

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