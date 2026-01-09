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
    int n; cin >> n;
    int pre = n * (n + 1) / 2;
    cout << "2 1 " << n << endl;
    int res; cin >> res;
    int len = res - pre;
    int l = 1, r = n;
    int ans = n;
    while(l <= r){
        int mid = (l + r) >> 1;
        cout << "1 1 " << mid << endl;
        int sum1; cin >> sum1;;
        cout << "2 1 " << mid << endl;
        int sum2; cin >> sum2;
        if(sum1 == sum2){
            l = mid + 1;
        }else{  
            ans = mid;
            r = mid - 1;
        }
    }
    cout << "! " << ans << " " << ans + len -1 << endl;
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