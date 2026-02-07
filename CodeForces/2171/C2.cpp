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
/*
    aji     mai
    1 0001  3 0011
    4 0100  2 0010
    6 0110  3 0011
    1 0001  7 0111
      eeae    eaea
    
    aji     mai
    2 0010  3 0011
    6 0110  4 0100
    3 0011  7 0111
    6 0110  1 0001
      
      eeea    eeea
    每一位奇偶性都相同tie

    2进制
*/
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1); // aji
    vector<int> b(n+1); // mai
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    int sum = 0;
    for(int i = 1; i <= n; i++){
        int op = a[i] ^ b[i];
        sum ^= op;
    }
    // cout << sum << endl;
    if(sum == 0){
        cout << "Tie" << endl;
        return;
    }
    int mx = 0;
    for(int i = 30; i >= 0; i--){
        if((sum >> i) & 1LL){
            mx = i;
            break;
        }
    }
    for(int i = n; i >= 1; i--){
        if(((a[i] >> mx) & 1LL) != ((b[i] >> mx) & 1LL)){
            if(i&1){
                cout << "Ajisai" << endl;
            }else{
                cout << "Mai" << endl;
            }
            return;
        }
    }
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