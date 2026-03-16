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
const int N = 1e6, mod = 1e9+7, inf = 2e18 + 5;
#define i128  __int128_t
/*
    gcd * lcm = a1 *a2 * ... * an
    lcm (a,b) = a / (gcd(a,b)) * b

    ans * (ans + 1) % (2 * lcm) == 0
    
*/
void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    int lcm = 1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        lcm = lcm / (__gcd(lcm,a[i])) * a[i];
    }
    // op = k * lcm
    // ans * (ans + 1) / 2 == op
    auto sqrt128 = [&] (i128 n) -> i128 {
        i128 l = 1,r = inf;
        i128 ans = 1;
        while(l <= r){
            i128 mid = (l + r) / 2;
            if(mid * mid <= n){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return ans;
    };
    for(int k = 1;; k++){
        i128 cur = 2 * k * lcm;
        int ans = sqrt128(cur);
        if(ans * (ans + 1) == cur){
            cout << (int)ans << endl;
            return;
        }
    }
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