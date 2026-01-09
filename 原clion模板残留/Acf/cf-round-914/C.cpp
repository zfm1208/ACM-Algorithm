//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18+5;
const int N = 2e5 + 5;

void solve() {
    int n,k; cin >> n >> k;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    if(k >= 3){
        cout << 0 << endl;
        return;
    }
    sort(a.begin() + 1,a.end());
    if(k == 1){
        int mn = inf;
        rep(i,2,n){
            mn = min(mn,a[i] - a[i-1]);
        }
        if(mn < a[1])cout << mn << endl;
        else cout << a[1] << endl;
    }else{
        int mn = inf;
        int ans = inf;
        rep(i,2,n){
            mn = min(mn,a[i] - a[i-1]);
        }
        if(mn < a[1]){
            if(abs(mn - a[1]) < mn){
                ans = abs(mn - a[1]);
            }else{
                ans = mn;
            }
        }else{
            if(abs(mn - a[1]) < a[1]){
                ans = abs(mn - a[1]);
            }else{
                ans = a[1];
            }
        }
        vector<int> c((n+1) * (n+1));
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                int x = abs(a[i]- a[j]);
                c.push_back(x);
            }
        }
        sort(c.begin(),c.end());
        for(int i = 1; i <= n; i++){
            //二分c数组 找>=a[i]的最小值
            int l = 0,r = c.size() - 1;
            while(l < r){
                int mid = (l + r) / 2;
                if(c[mid] >= a[i]){
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }
            ans= min(ans,abs(c[l] - a[i]));
            // 二分c数组 找<=a[i]的最大值
            l = 0,r = c.size() - 1;
            while(l < r){
                int mid = (l + r + 1) / 2;
                if(c[mid] <= a[i]){
                    l = mid;
                }else{
                    r = mid - 1;
                }
            }
            ans = min(ans,abs(a[i] - c[l]));
        }
        cout << ans << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}