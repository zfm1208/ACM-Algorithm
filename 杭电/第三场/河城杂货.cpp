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
#define i128 __int128_t
// https://acm.hdu.edu.cn/contest/problem?cid=1199&pid=1001
void solve(){
    int n,m; cin >> n >> m;
    vector<int> a(n+1),b(n+2);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n+1) cin >> b[i];
    sort(a.begin()+1,a.end(),greater<int>());
    sort(b.begin()+1,b.end(),greater<int>());
    auto check = [&](int mid) -> bool {
        i128 sum = 0, ok = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] > mid) sum += (i128)a[i] * b[i];
            else{
                if(ok == 0){
                    ok = 1;
                    sum += (i128)mid * b[i];
                }
                sum += (i128)a[i] * b[i+1];
            }
            if(sum >= (i128)m) return true;
        }
        if(ok == 0){
            sum += (i128)mid * b[n+1];
        }
        return(sum >= (i128)m);
    };
    int l = 0,r = inf;
    int ans = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    cout << ans << endl;
}
// void solve(){
//     int n, m;  cin >> n >> m;
//     vector<int> a(n+1);
//     rep(i,1,n) cin >> a[i];
//     vector<int> b(n+2);
//     rep(i,1,n + 1) cin >> b[i];
//     sort(a.begin()+1,a.begin()+n+1, greater<int>());
//     sort(b.begin()+1,b.begin()+n+2, greater<int>());
//     vector<i128> pre(n+2), suf(n+2);
//     rep(i,1,n) pre[i] = pre[i - 1] + (i128)a[i] * b[i];
//     for(int i = n; i >= 1; i--){
//         suf[i] = suf[i + 1] + (i128)a[i] * b[i + 1];
//     }
//     int ans = inf;
//     rep(k, 1, n + 1){
//         i128 x = pre[k - 1] + suf[k];
//         if((i128)m > x){
//             int diff = m - x;
//             i128 res = (int)((diff + b[k] - 1) / b[k]);
//             ans = min(ans, (int)res);
//         }else{
//             ans = 0;
//             break;
//         }
//     }
//     cout << ans << endl;
// }

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}
