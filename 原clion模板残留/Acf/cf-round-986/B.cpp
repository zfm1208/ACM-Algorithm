//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

void solve() {
    // 每次取最大的数进行MEX  当b==0,n-c >= 3时会进入死循环
    int n,b,c; cin >> n >> b >> c;
    if(c >= n){cout << n << endl; return;}
    else{
        if(b ==0){
            if(n-c >= 3){cout << -1 << endl; return;}
            else{cout << n-1 << endl; return;}
        }else{cout << n-(n-c-1)/b-1 << endl; return;}
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
