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
/*
    n = 7
    !!i : 1  cnt: 64
    !!i : 2  cnt: 96
    !!i : 3  cnt: 112
    !!i : 4  cnt: 120
    !!i : 5  cnt: 124
    !!i : 6  cnt: 126
    !!i : 7  cnt: 127

    n = 6
    !!i : 1  cnt: 32 (1 << 5)
    !!i : 2  cnt: 48 (1 << 5) + (1 << 4)
    !!i : 3  cnt: 56 (1 << 5) + (1 << 4) + (1 << 3)
    !!i : 4  cnt: 60 (1 << 5) + (1 << 4) + (1 << 3) + (1 << 2)
    !!i : 5  cnt: 62 (1 << 5) + (1 << 4) + (1 << 3) + (1 << 2) + (1 << 1)
    !!i : 6  cnt: 63 (1 << 5) + (1 << 4) + (1 << 3) + (1 << 2) + (1 << 1) + (1 << 0)


    n = 5
    !!i : 1  cnt: 16
    !!i : 2  cnt: 24
    !!i : 3  cnt: 28
    !!i : 4  cnt: 30
    !!i : 5  cnt: 31
    
    n = 4  
    !!i : 1  cnt: 8  (1 << 3)
    !!i : 2  cnt: 12 (1 << 3) + (1 << 2)
    !!i : 3  cnt: 14 (1 << 3) + (1 << 2) + (1 << 1)
    !!i : 4  cnt: 15
*/
int ksm(int a, int b) {
    int res = 1;
    // a %= mod;
    while (b) {
        if (b & 1) res = res * a ;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n,k; cin >> n >> k;
    bool ok = 0;
    while(k > 0){
        int op = 1;
        while(1){
            if(n-op >= 60 || k <= ksm(2,n-op)){
                cout << op << " ";
                k--;
                n -= op;
                if(k <= 0) {
                    ok = 1;
                    break;
                }
                break;
            }else{
                op++;
                k -= ksm(2,n-op+1);
            }
        }
        if(ok == 1) break;
    }
    cout << endl;
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