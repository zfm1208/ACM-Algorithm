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
    int n,m,k; cin >> n >> m >> k;
    int l = k,r = k;
    int sum = 0;
    while(l >= 1 && r <= n){
        int lenl = k-l,lenr = r-k;
        int cl = inf,cr = inf;
        // 若向左移动
        if(l > 1){
            if(lenl == 0 && lenr == 0) cl = 1;
            else cl = (lenl < lenr) ? 1 : 2;
        }
        // 若向右移动
        if(r < n){
            if(lenl == 0 && lenr == 0) cr = 1;
            else cr = (lenr < lenl) ? 1 : 2;
        }
        if(sum + min(cl,cr) > m) break;
        sum += min(cl,cr);
        if(cl < cr){
            l--; 
        }else if(cl > cr){
            r++;
        }else{
            if(l > 1) l--;
            else r++;
        }
        if(l == 1 && r == n) break;
    }
    cout << r-l+1 << endl;
}

void solve1(){
    int n,m,k; cin >> n >> m >> k;
    int ans = 0;
    auto check = [&] (int mid) -> int {
        int l = mid >> 1,r = mid - l;
        if(l > k-1){
            r += (l - (k-1));
            l = k-1;
        }
        if(r > n-k){
            l += (r - (n-k));
            r = n-k;
        }
        if(l > k-1 || r > n-k) return false;
        return ((min(l,r) + max(l,r) * 2 - 1) <= m);
    };
    int l = 0,r = n-1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << ans + 1 << endl;
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