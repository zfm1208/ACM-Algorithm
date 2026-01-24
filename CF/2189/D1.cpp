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
    si = 1,存在一个区间，使得[0~i-1]都在里面且不含i
    si = 0,不存在上述这样区间
    也就是存在一个区间使得[0~i-1]都在里面里面，i在这里面且在这些数中间
    不对，要让所有i都满足条件，只能0-n-1依次放
    si = 0,放中间
    si = 1,放两边
*/
void solve(){
    int n,c; cin >> n >> c;
    string s; cin >> s;
    s = " " + s;
    pii ans = {1,1};
    if(s[n] == '0'){
        cout << -1 << endl;
        return;
    }
    for(int i = 1; i < n; i++){
        if(s[i] == '1'){
            ans.fi = ans.fi * 2 % mod;
            ans.se = ans.se * 2 % c;
        }else{
            ans.fi = ans.fi * (i-1) % mod;
            ans.se = ans.se * (i-1) % c;
        }
    }
    if(ans.se == 0){
        cout << -1 << endl;
    }else{
        cout << ans.fi << endl;
    }
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