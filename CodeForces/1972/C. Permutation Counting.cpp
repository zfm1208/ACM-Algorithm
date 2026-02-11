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
    ! 以 . . 1 2 3 4 1 2 3 4 1 2 ..的顺序不一定是最优的!!!

    * 注意二分的边界，这一题r 设为 inf ，会wa，要么剪枝，要么设立合理r
*/
void solve(){
    int n,k; cin >> n >> k;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int sum = 0;
    auto check = [&] (int mid) -> bool {
        sum = 0;
        for(int i = 1; i <= n; i++){
            sum += max(0LL, mid - a[i]);
        }
        return sum <= k;
    };
    int l = 0,r = 2e12;
    int ave = 0;
    int tot = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            tot = sum;
            ave = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    k -= tot;
    int ans = n * ave - n  + 1 + k;
    for(int i = 1; i <= n; i++){
        if(a[i] > ave) ans++;
    }
    cout << ans << endl;
    return;   
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