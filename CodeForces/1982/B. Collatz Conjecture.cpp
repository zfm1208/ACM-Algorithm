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
    int x,y,k; cin >> x >> y >> k;
    k--;
    x++;
    while(x % y == 0){
        x /= y;
    }
    while(1){
        int cnt = y - x % y;
        if(k - cnt >= 0){
            k -= cnt;
            x += cnt;
            while(x % y == 0){
                x /= y;
            }
            if(x == 1){
                k %= (y-1);
            }
        }else{
            x += k;
            cout << x << endl;
            return;
        }
    }
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