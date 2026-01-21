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
    int n,ex,ey; cin >> n >> ex >> ey;
    int u = 1, d = n;
    int l = 1, r = n;
    vector<array<int,4>> ans;
    while(ex > u && ey < r){
        ans.pb({u, r, d-u, l-r});
        u++; 
        r--;
    }
    while(ex < d && ey > l){
        ans.pb({d, l, u-d, r-l});
        d--; 
        l++; 
    }
    while(u != d || l != r) {
        if (ex == u){ 
            if(ey == r) { ans.pb({d, l, u-d, r-l}); d--; l++; } 
            else        { ans.pb({d, r, u-d, l-r}); d--; r--; } 
        }
        else if(ex == d){ 
            if(ey == l) { ans.pb({u, r, d-u, l-r}); u++; r--; } 
            else        { ans.pb({u, l, d-u, r-l}); u++; l++; } 
        }
        else if(ey == l){ 
            ans.pb({u, r, d-u, l-r}); u++; r--; 
        }
        else{
            ans.pb({u, l, d-u, r-l}); u++; l++;
        }
    }
    cout << "Yes" << endl;
    cout << ans.size() << endl;
    for(auto [p1,p2,p3,p4] : ans){
        cout << p1 << " " << p2 << " " << p3 << " " << p4 << endl;
    }
    cout << endl;
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