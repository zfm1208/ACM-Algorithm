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
/*
    p : q = 2 : 3
    2 3  1
    4 6  2
    6 9  3
    8 12  4
    10 15  5

    2 3 = 0.66
    4 5 = 0.8    4 7 = 0.57
    3 4 = 0.75   3 6 = 0.5
    2 3 = 0.66

    4 / 7  < 2 / 3

*/
void solve(){
    int p,q; cin >> p >> q;
    if(p == q){
        cout << "Alice" << endl;
        return;
    }
    if(p * 3 < 2 * q){
        cout << "Alice" << endl;
        return;
    }
    if(p * 3 == 2 * q){
        cout << "Bob" << endl;
        return;
    }
    // p/q > 2/3
    int gcd = __gcd(p,q);
    p /= gcd;
    q /= gcd;
    if(q > p){
        cout << "Bob" << endl;
    }else{
        cout << "Alice" << endl;
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