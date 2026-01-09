#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
double pi = acos(-1);
const int N = 5e6, mod = 1e9+7, inf = 1e18 + 5;
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
vector<int> su,vis(N + 100);
void shai(){
    for(int i = 2; i <= N; i++){
        if(!vis[i]){
            su.pb(i);
            for(int j = i*i; j <= N; j+=i){
                vis[j] = 1;
            }
        }
    }
}
void solve() {
    int n; cin >> n;            
    // 答案具有唯一性质
    // n = p * p * q (p,q素数)
    // 7 * 7 * 17  合法
    // 7 * 7 * 7 * 13       不合法
    // 7 * 7 * 7 * 7 * 13 * 13 不合法
    // 7 * 13 * 13
    
    for(auto &x: su){
        if(n % x == 0){
            int cnt = 0;
            while(n % x == 0){
                n /= x;
                cnt++;
            }
            if(cnt == 2){
                cout << x << " " << n << endl;
                return;                
            }
            else{
                cout << (int)sqrt(n) << " " << x << endl;
                return;
            }
        }        
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;shai();
    cin >> T;
    while (T--)
        solve();
    return 0;
}