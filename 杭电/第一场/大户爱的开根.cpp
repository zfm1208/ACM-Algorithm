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
    int n,k; cin >> n >> k;
    int ans = 0;
    int l = 1,r = n;
    auto check = [&](int mid) -> bool {
        if(mid  == 1) return true;
        int op = 1;
        for(int i = 1; i <= k; i++){
            if(op > n / mid) return false;
            op *= mid;
        }
        if(op == -1) return false;
        return (op <= n);
    };
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
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