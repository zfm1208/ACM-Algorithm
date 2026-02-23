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
    int n,h,k; cin >> n >> h >> k;
    vector<int> a(n+1);
    int sum = 0;
    vector<int> pre(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
        pre[i] = pre[i-1] + a[i];
    }
    
    vector<int> pmn(n+1,inf);
    for(int i = 1; i <= n; i++){
        pmn[i] = min(pmn[i-1],a[i]);
    }
    vector<int> smx(n+2);
    for(int i = n; i >= 1; i--){
        smx[i] = max(smx[i+1],a[i]);
    }
    auto check = [&] (int mid) -> bool {
        int ci = mid / (n+k);
        int rem = mid % (n+k);
        int t1 = min(rem,n);
        // if (ci >= (h + sum - 1) / sum) return true;
        __int128_t res = (__int128_t)ci * sum + pre[t1];
        if(t1 == 0 || t1 >= n){
            return res >= h;
        }
        res += max(0LL, smx[t1+1] - pmn[t1]); 
        return res >= h;
    };

    int l = 1,r = inf;
    int ans = inf;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        }else l = mid + 1;
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