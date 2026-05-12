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
const int N = 1e6, mod = 1e9+7, inf = 3e18 + 5;

void solve(){
    int n,k; cin >> n >> k;
    vector<int> a(n+1);
    int mn = inf;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    int l = mn, r = inf;
    int ans = l;
    auto check = [&] (int tar) -> bool {
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] < tar){
                cnt += (tar - a[i] + i - 1) / i;
                if(cnt > k) return false;
            }
        }
        return cnt <= k;
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
    // cin >> T;
    while(T--)
        solve();
    return 0;
}