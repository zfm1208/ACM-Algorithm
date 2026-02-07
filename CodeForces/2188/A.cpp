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

void solve(){
    int n; cin >> n;
    /*
        1 2 3 4
        3 2 4 1

        1 2 3 4 5 6
        2 3 5 2 6 1
    */
    vector<int> ans(n+1);
    int l = 1, r = n;
    for(int i = n; i >= 1; i--){
        if((n-i) & 1){
            ans[i] = r;
            r--;
        }else{
            ans[i] = l;
            l++;
        }
    }
    rep(i,1,n) cout << ans[i] << " \n"[i==n];
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