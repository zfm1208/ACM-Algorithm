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
       1  2 4 8 16
    14 0  1 1 1 0
   ans 0 -1 0 0 1 

    0  1  2  3  4  5  6
    1  2  4  8  16 32 64
24: 0  0  0  1  1  0  0
ans:0  0  0  -1 0  1  0

    0  1  2  3  4  5  6
    1  2  4  8  16 32 64
11: 1  1  0  1  0  
ans:-1 0  1  1
*/


void solve(){
    int n; cin >> n;
    vector<int> a(40);
    for(int i = 0; i < 32; i++){
        if((n >> i) & 1){
            a[i] = 1;
        }
    }
    int cnt = 0;
    for(int i = 0; i < 32; i++){
        if(a[i] == 1){
            int j = i+1;
            if(a[j] == 0) continue;
            a[i] = -1;         
            while(a[j] == 1) {
                a[j] = 0;
                j++;
            }
            a[j] = 1;
            i = j-1;
        }
    }
    int p = 100;
    for(int i = 31; i>=0; i--){
        if(a[i] != 0){
            p = i;
            break;
        }
    }
    cout << p+1 << endl;
    rep(i,0,p) cout << a[i] << " ";
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