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
    int p, q;
    cin >> p >> q;
    int sum = 2 * p + 4 * q + 1;
    // (2*m+1) * (2*n+1) = sum
    for(int A = 3; A * A <= sum; A += 2){
        if(sum % A == 0){
            int B = sum / A;
            int n = (A - 1) / 2;
            int m = (B - 1) / 2;
            if(q <= n * (m + 1) && q <= m * (n + 1)){
                cout << n << " " << m << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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