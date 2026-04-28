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
    int a,b,n,m,h;
    cin >> a >> b >> n >> m >> h;
    int ans = n + m;
    int l = n+1,r = n+m;
    while(l <= r){
        // mid 即为当前假设的宽度 W
        int mid = (l + r) / 2;
        // 当前宽度下的最大容量
        int cnt = 0;
        if(n >= b){
            cnt += (b - a) * (n / b);
        }
        if(mid >= b){
            cnt += (h - b) * (mid / b);
        }
        // 总容量 + 当前宽度 >= 初始总书数
        if(cnt + mid >= n + m){
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
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