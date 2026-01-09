//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define per(i,l,r) for(int i = l; i >= r; i--)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
double pi = acos(-1);
const int mod1 = 1e9 + 7,mod2 = 998244353,inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

void solve() {
//    想复杂了
    int n; cin >> n;
    string a,b;
    cin >> a >> b;
    a = " " + a;
    b = " " + b;
    int s1 = 0,s2 = 0;
    for(int i = 1; i <= n; i++){
        if(i&1) {
            if(a[i] == '0') s1++;
            if(b[i] == '0') s2++;
        }
        if(i%2==0) {
            if(b[i] == '0') s1++;
            if(a[i] == '0') s2++;
        }
    }
    if((n%2==0 && s1 >= n/2 && s2 >= n/2 )||( n%2==1 && s1 >= n/2+1 && s2 >= n/2)) cout << "YES" << endl;
    else cout << "NO" << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
