#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define vii vector<int>
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
    string s; cin >> s;
    s = " " + s;
    vector<int> pre(n+2), suf(n+2);
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i - 1];
        if(s[i] == '(') pre[i]++;
    }
    for(int i = n; i >= 1; i--){
        suf[i] = suf[i+1];
        if(s[i] == ')') suf[i]++;
    }
    // vii ans(n+1);
    int mn = inf;
    int jl = 0, jl2 = 0;
    for(int x = 0; x <= pre[n]; x++){
        if(x > k) break;
        int y = min(suf[1], k - x);
        int cur = inf;
        for(int i = 0; i <= n; i++){
            cur = min(cur, max(0LL, pre[i] - x) + max(0LL, suf[i+1] - y));
        }
        if(cur < mn){
            mn = cur;
            jl = x;
            jl2 = y;
        }
    }
    string ans;
    for(int i = 1; i <= n; i++){
        if(s[i] == '('){
            if(pre[i] <= jl){
                ans.pb('1'); 
            }else ans.pb('0');
        }else {
            if(suf[i] <= jl2){
                ans.pb('1');
            }else{
                ans.pb('0');
            }
        }
    }
    cout << ans << endl;
    // int pos = 1;
    // int z = -1, y = -1; 
    // int mx = 0;
    // for(int i = 1; i <= n; i++){
    //     int op = min(pre[i], suf[i+1]);
    //     if(2 * op > mx){
    //         op = mx;
    //         pos = i;
    //     }
    // }
    
    // auto check = [&](int mid) -> bool {

    // };
    // int l = 0, r = inf;
    // int res = 0;
    // while(l <= r){
    //     int mid = l + r >> 1;
    //     if(check(mid)){
    //         res = mid;
    //         l = mid + 1;
    //     }else {
    //         r = mid - 1;
    //     }
    // }

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