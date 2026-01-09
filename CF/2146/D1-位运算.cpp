// 律己则安，越是执着，便是越苦;
// 安下心来，看该看的风景，做该做的事。
#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r)for(int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define aaa "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
double pi = acos(-1);
const int N = 2e5 + 10, mod = 1e9+7, inf = 1e18 + 5;
void solve(){ 
    int l,r; cin >> l >> r;
    vector<int> ans(r+1,-1);
    int res = 0;
    int mx = 0;
    while((1 << mx) - 1 <= r) mx++;mx--;
    if((1 << mx) - 1  == r){
        int op = r;
        for(int i = 0; i <= r; i++){
            res += (i | op--);
        }
        cout << res << endl;
        for(int i = r; i >= 0; i--){
            cout << i << " \n"[i==0];
        }
        return;
    }
    auto get = [&](int x, int lg) -> int {
        vector<int> v;
        while(x){
            v.pb(x%2);
            x >>= 1;
        }
        while(v.size() < lg) v.pb(0);
        reverse(v.begin(),v.end());
        int res = 0;
	    for(auto p : v) res = (res<<1) + (1-p);
	    return res;
    };
    for(int i = mx; i >= 0; i--){
        for(int x = r; x >= 0; x--){
            int io = get(x,i);
            if(ans[x] == -1 && ans[io] == -1){
                ans[x] = io;
                ans[io] = x;
            }
        }
    }
    if(r % 2 == 0) ans[0] = 0;
    for(int i = 0; i <= r; i++){
        res += (i | ans[i]);
    }
    cout << res << endl;
    for(int i = 0; i <= r; i++){
        cout << ans[i] << " \n"[i==r];
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}