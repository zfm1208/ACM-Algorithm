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
void solve() {
    int n,x,y; cin >> n >> x >> y;
    x = abs(x),y = abs(y);
    string s; cin >> s;
    for(auto & c: s){
        if(c == '4'){
            if(x > y){
                x--;
            }else if(y > 0){
                y--;
            }
        }else {
            x = max(x - 1,0LL);
            y = max(y - 1,0LL);            
        }
    }        
    if(y == 0 && x == 0){
        cout << "YES" << endl;
    }  
    else cout << "NO" << endl;  
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
} 